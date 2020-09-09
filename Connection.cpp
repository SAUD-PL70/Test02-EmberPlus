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
#include "TestEmberTree.h"
#include "Connection.h"

Connection::Connection(Server* srv, wxSocketBase* cli)

{
    this->server = srv;
    this->client = cli;
    ember = new TestEmberTree(this,&server->leds);
    
    Bind(wxEVT_SOCKET,[this](wxSocketEvent& ev){
        if(ev.m_event==wxSOCKET_LOST)
        {
            for(std::list<Connection*>::iterator it=this->server->connections.begin();it!=this->server->connections.end();it++)
                if(*it==this){
                    this->server->connections.erase(it);
                    delete this;
                    break;
                }
        }
        if(ev.m_event==wxSOCKET_INPUT)
        {
            char buffer[2048];
            
            ev.GetSocket()->Read((void*)&buffer,2048);
            
            uint32_t size = ev.GetSocket()->LastReadCount();
            
            ember->Decode((void*)&buffer,size);
            
            if(ember->hasResponse())
                ev.GetSocket()->Write(ember->getBuffer(),ember->getSize());
        }
    });
    if(IsOk())
    {
        client->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
//        client->SetFlags(wxSOCKET_WAITALL);
        client->SetEventHandler(*this);
        client->Notify(true);
    }
}

Connection::~Connection()
{
    delete ember;
    Unbind(wxEVT_SOCKET,[this](wxSocketEvent& ev){});
    if(client!=nullptr)
    {
        if(IsOk())
        {
            wxCommandEvent* ev = new wxCommandEvent(CONNECTION_CLOSED);
            server->evthandler->QueueEvent(ev);
        }
        while(!client->Destroy());
    }
}

Led::Led(int id, bool state, Server* server)
{
    this->id = id;
    this->state = state;
    this->server = server;
    str = "Led ";
    str += std::to_string(id);
}

void Led::setState(bool state)
{
    if(this->state!=state)
    {
        this->state = state;
        wxCommandEvent* ev;
        if(state)
            ev = new wxCommandEvent(LED_ON,id);
        else
            ev = new wxCommandEvent(LED_OFF,id);
        server->evthandler->QueueEvent(ev);
    }
}

Server::Server(wxEvtHandler* handler, const std::string& ip_str, int port)
{
    evthandler = handler;
    wxIPV4address ip;
    ip.Hostname(ip_str);
    ip.Service(port);
    server=nullptr;
    
    this->Bind(wxEVT_SOCKET,[&](wxSocketEvent& ev){
        if(ev.m_event==wxSOCKET_CONNECTION)
        {
            if(server!=nullptr)
            {
                wxSocketBase* client = server->Accept(false);
                Connection* connection = new Connection(this,client);
                if(connection->IsOk())
                {
                    connections.insert(connections.end(), connection);
                    wxCommandEvent* ev = new wxCommandEvent(CONNECTION_RECEIVED);
                    evthandler->QueueEvent(ev);
                }
                else
                {
                    delete connection;
                    wxCommandEvent* ev = new wxCommandEvent(CONNECTION_ERROR);
                    evthandler->QueueEvent(ev);
                }
            }
        }
    });
    
    server = new wxSocketServer( ip );
    if(server!=nullptr)
    {
        server->SetEventHandler( *this );
        server->SetFlags(wxSOCKET_REUSEADDR);
        server->SetNotify( wxSOCKET_CONNECTION_FLAG );
        server->Notify( true );
    }
}

void Server::AddLed(int id, bool state)
{
    Led* led = new Led(id, state, this);
    leds.insert(leds.end(), led);
}

Server::~Server()
{
    this->Unbind(wxEVT_SOCKET,[this](wxSocketEvent& ev){});
    for(auto it=leds.begin();it!=leds.end();it++)
        delete *it;
    for(auto it=connections.begin();it!=connections.end();it++)
        delete *it;
    if(server!=nullptr)
        while(!server->Destroy());
}
