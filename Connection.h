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

class Connection {
public:
    Connection(wxEvtHandler* evthandler,const std::string& ip, int port);
    void AddLed(wxEventTypeTag<wxCommandEvent>& on, wxEventTypeTag<wxCommandEvent>& off);
    virtual ~Connection();
private:
    class Led  {
        public:
            Led(Connection * obj, wxEventTypeTag<wxCommandEvent>* on, wxEventTypeTag<wxCommandEvent>* off);
            std::string toString() { return str; }
            bool getState() { return state; }
            void setState(bool state);
            virtual ~Led();
        private:
            static int numleds;
            Connection* obj;
            std::string str;
            bool state;
            wxEventTypeTag<wxCommandEvent>* on;
            wxEventTypeTag<wxCommandEvent>* off;
    };
    void OnSocketEvt(wxSocketEvent& ev);
    std::list<wxSocketBase*> connections;
    std::list<Led*> leds;
    wxSocketServer* server;
    wxEvtHandler* evthandler;
};

#endif /* CONNECTION_H */
