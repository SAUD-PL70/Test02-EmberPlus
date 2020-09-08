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

#ifndef CONNECTION_H
#define CONNECTION_H

class Server;

/**
 * Manages to connection to the ember consumers
 */
class Connection : public wxEvtHandler{
public:
    Connection(Server* server, wxSocketBase* client);
    virtual ~Connection();
    bool IsOk() const { return client!=nullptr?!client->Error():false; }
    bool IsConnected() { return client->IsConnected(); }
private:
    Server* server;
    wxSocketBase* client;
};

/**
 * This class is responsible to keep the Led state and send state change events 
 */
class Led  {
public:
    Led(int id, bool state, Server* server);
    void setState(bool state);
    std::string toString() { return str; }
    bool getState() { return state; }
    int getId() const { return id; }
private:
    int id;
    std::string str;
    bool state;
    Server* server;
};

/**
 * Listen for new connections and maintains a bridge between the GUI and the
 * client connections
 */
class Server : public wxEvtHandler {
    friend class Led;
    friend class Connection;
public:
    typedef std::list<Led*> Leds;
    Server(wxEvtHandler* evthandler, const std::string& ip_str, int port);
    void AddLed(int id, bool state=false);
    bool IsOk() const { return server!=nullptr? server->IsOk(): false; }
    virtual ~Server();
private:
    Leds leds;
    std::list<Connection*> connections;
    wxEvtHandler* evthandler;
    wxSocketServer* server;
};
#endif /* CONNECTION_H */
