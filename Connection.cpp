/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Connection.cpp
 * Author: josepva
 * 
 * Created on 3 de setembro de 2020, 09:59
 */
#include "Connection.h"

int Connection::Led::numleds=0;

Connection::Connection(wxEvtHandler* evthandler,const std::string& ip_str, int port)
{
    this->evthandler = evthandler;
    
    wxIPV4address ip;
    ip.Hostname(ip_str);
    ip.Service(port);

    evthandler->Bind(wxEVT_SOCKET,[&](wxSocketEvent& ev){
        OnSocketEvt(ev);
    });
    
    server = new wxSocketServer(ip);
    server->SetNotify(12);
    server->SetEventHandler(*evthandler);
    server->Notify(true);
}

void Connection::AddLed(wxEventTypeTag<wxCommandEvent>& on,
        wxEventTypeTag<wxCommandEvent>& off)
{
    leds.insert(leds.end(),new Connection::Led(this,&on,&off));
}

Connection::~Connection()
{
    server->Destroy();
    for(auto it=connections.begin();it!=connections.end();it++)
    {
//        wxSocketEvent* ev = new wxSocketEvent(); 
//        ev->m_event = wxSOCKET_LOST;
        (*it)->Destroy();
//        evthandler->QueueEvent(ev);
    }
    connections.erase(connections.begin(),connections.end());
    for(auto it=leds.begin();it!=leds.end();it++)
    {
        delete *it;
    }
    leds.erase(leds.begin(),leds.end());
    evthandler->Unbind(wxEVT_SOCKET,[&](wxSocketEvent& ev){});
}

Connection::Led::Led(Connection* obj, wxEventTypeTag<wxCommandEvent>* on, wxEventTypeTag<wxCommandEvent>* off)
{
    numleds++;
    this->obj = obj;
    this->on = on;
    this->off = off;
    state = false;
    str = "Led ";
    str += std::to_string(numleds);
}

void Connection::Led::setState(bool state)
{
    if(this->state!=state)
    {
        this->state = state;
        if(state)
            obj->evthandler->QueueEvent(new wxCommandEvent(*on));
        else
            obj->evthandler->QueueEvent(new wxCommandEvent(*off));
    }
}

Connection::Led::~Led()
{
    
}

void Connection::OnSocketEvt(wxSocketEvent& ev)
{
    if(ev.GetSocketEvent()==wxSOCKET_CONNECTION)
    {
        wxSocketBase* connection = server->Accept(false);
        if(connection->IsConnected())
        {
            connection->SetNotify(9);
            connection->SetTimeout(2);
            connection->SetEventHandler(*evthandler);
            connection->Notify(true);
            connections.insert(connections.end(),connection);
        }
        else
            connection->Destroy();
    }
    if(ev.GetSocketEvent()==wxSOCKET_LOST)
    {
        for(auto it=connections.begin();it!=connections.end();it++)
        {
            if((*it)->IsDisconnected())
            {
                (*it)->Destroy();
                connections.erase(it);
            }
        }
    }
    ev.Skip();
}
