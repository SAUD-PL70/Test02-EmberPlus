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

class Connection {
public:
    Connection();
    bool Connect();
    void Disconnect();
    void AddLed(void (*setled)(bool state));
    virtual ~Connection();
private:
    std::list<wxSocketBase*> connections;
    std::list<void(*)(bool)> leds;
};

#endif /* CONNECTION_H */
