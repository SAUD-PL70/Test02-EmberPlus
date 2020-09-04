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

Connection::Connection(wxEvtHandler* evthandler)
{
    this->evthandler = evthandler;
}

bool Connection::Connect(const std::string& ip, int port)
{
    wxIPV4address ip;
    ip.Hostname(ip);
    ip.Service((unsigned short)port);
    server = new wxSocketServer(ip);
    server->SetEventHandler(evthandler);
    server->SetNotify(0x0f); //All notifies
    evthandler->Bind(wxEVT_SOCKET, [&](wxSocketEvent& ev)
    {
        switch(ev.GetSocketEvent())
        {
            case wxSocketNotify::wxSOCKET_CONNECTION:
                connections.insert(connections.end(),server->Accept(false));
                evthandler->QueueEvent(new wxCommandEvent(CONNECTION_ACQUIRED));
                break;
            case wxSocketNotify::wxSOCKET_LOST:
                break;
            case wxSocketNotify::wxSOCKET_INPUT:
                break;
            case wxSocketNotify::wxSOCKET_OUTPUT:
                break;
        }
    });
    server->Notify(true);
}

void Connection::Disconnect()
{
    
}

void AddLed(const std::string& str)
{
    
}

virtual Connection::~Connection()
{
    
}
