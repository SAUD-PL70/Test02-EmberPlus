/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Connection.h
 * Author: josepva
 *
 * Created on 3 de setembro de 2020, 09:59
 */
#include <wx/socket.h>
#include <list>
#include "events.h"
#include <thread>

#ifndef CONNECTION_H
#define CONNECTION_H

class Client;
class Led;

class Service {
    friend class Client;
    friend class Led;
public:
    Service(wxEvtHandler* evthandler,const std::string& ip, int port);
    void AddLed(int ledid);
    virtual ~Service();
private:
    std::list<Client*> clients;
    std::list<Led*> leds;
    wxSocketServer* server;
    wxEvtHandler* evthandler;
    std::thread thread;
    bool finish;
};

class Led  {
public:
    Led(Service * service, int ledid);
    std::string toString() { return str; }
    bool getState() { return state; }
    void setState(bool state);
    virtual ~Led();
private:
    int ledid;
    Service* service;
    std::string str;
    bool state;
};

class Client {
public:
    Client(Service* service, wxSocketBase * connection);
    int getConnectionID() { return connectionid; }
    ~Client();
private:
    wxSocketBase* connection;
    std::thread thread;
    bool finish;
    static int connectioncounter;
    int connectionid;
    Service* service;
};
#endif /* CONNECTION_H */
