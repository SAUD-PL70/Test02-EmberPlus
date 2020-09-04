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

#ifndef CONNECTION_H
#define CONNECTION_H

#define CONNECTION_ACQUIRED wxEVT_USER_FIRST
#define CONNECTION_LOST     CONNECTION_ACQUIRED+1
#define LED_SET             CONNECTION_LOST+1
#define LED_UNSET           LED_SET+1

class Connection : public wxEvtHandler {
public:
    Connection(wxEvtHandler* evthandler);
    bool Connect(const std::string& ip, int port);
    void Disconnect();
    void AddLed(const std::string& str);
    virtual ~Connection();
private:
    std::list<wxSocketBase*> connections;
    std::list<std::string> leds;
    wxSocketServer* server;
    wxEvtHandler evthandler;
};

#endif /* CONNECTION_H */
