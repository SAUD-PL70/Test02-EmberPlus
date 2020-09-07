/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   events.h
 * Author: SAUD-DEVOPS
 *
 * Created on 4 de setembro de 2020, 20:38
 */
#include <wx/wx.h>

#ifndef EVENTS_H
#define EVENTS_H
wxDEFINE_EVENT(LED_ON, wxCommandEvent);
wxDEFINE_EVENT(LED_OFF, wxCommandEvent);
wxDEFINE_EVENT(CONNECTION_LOST, wxCommandEvent);
wxDEFINE_EVENT(CONNECTION_RECEIVED, wxCommandEvent);
#endif /* EVENTS_H */

