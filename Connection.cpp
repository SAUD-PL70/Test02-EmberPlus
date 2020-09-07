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
#include <chrono>

Service::Service(wxEvtHandler* evthandler,const std::string& ip_str, int port)
{
    this->evthandler = evthandler;
    finish = false;
    
    wxIPV4address ip;
    ip.Hostname(ip_str);
    ip.Service(port);

    server = new wxSocketServer(ip);
    server->SetFlags(wxSOCKET_REUSEADDR | wxSOCKET_BLOCK );
    
    std::thread thread([this](){
        while(this->server!=nullptr && !this->finish)
        {
            if(this->server->WaitForAccept(0,100))
            {
                wxSocketBase* connection = server->Accept();
                if(connection!=nullptr)
                {
                    this->clients.insert(this->clients.end(),new Client(this, connection));
                    wxCommandEvent* ev = new wxCommandEvent(CONNECTION_RECEIVED);
                    this->evthandler->QueueEvent(ev);
                }
            }
        }
        if(this->server!=nullptr)
            this->server->Destroy();
    });
    this->thread.swap(thread);
}

Service::~Service()
{
    for(auto it=clients.begin();it!=clients.end();it++)
    {
        delete *it;
    }
    clients.erase(clients.begin(),clients.end());
    for(auto it=leds.begin();it!=leds.end();it++)
    {
        delete *it;
    }
    leds.erase(leds.begin(),leds.end());
    finish=true;
    thread.join();
}

void Service::AddLed(int ledid)
{
    leds.insert(leds.end(),new Led(this,ledid));
}

Led::Led(Service* service, int ledid)
{
    this->ledid = ledid;
    this->service = service;
    state = false;
    str = "Led ";
    str += std::to_string(ledid);
}

void Led::setState(bool state)
{
    if(this->state!=state)
    {
        this->state = state;
        if(state)
            service->evthandler->QueueEvent(new wxCommandEvent(LED_ON,ledid));
        else
            service->evthandler->QueueEvent(new wxCommandEvent(LED_OFF,ledid));
    }
}

Led::~Led()
{
    
}

int Client::connectioncounter=0;

Client::Client(Service* service, wxSocketBase* connection)
{
    this->connection = connection;
    this->service = service;
    finish=false;
    connectionid = connectioncounter;
    connectioncounter++;
    std::thread t([this](){
        while(this->connection!=nullptr && !this->finish)
        {
            if(this->connection->WaitForLost(0,50))
            {
                this->finish=true;
            }
            if(this->connection->WaitForRead(0,50))
            {
                //@todo Implementar leitura de dados vindos do cliente remoto
                this->connection->Discard();
            }
        }
        if(this->connection!=nullptr)
            this->connection->Destroy();
        wxCommandEvent* ev = new wxCommandEvent(CONNECTION_LOST,this->connectionid);
        this->service->evthandler->QueueEvent(ev);
    });
    thread.swap(t);
}

Client::~Client()
{
    finish=true;
    thread.join();
}