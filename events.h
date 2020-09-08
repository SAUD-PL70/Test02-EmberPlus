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
wxDECLARE_EVENT(LED_ON, wxCommandEvent);
wxDECLARE_EVENT(LED_OFF, wxCommandEvent);
wxDECLARE_EVENT(CONNECTION_RECEIVED, wxCommandEvent);
wxDECLARE_EVENT(CONNECTION_CLOSED, wxCommandEvent);
wxDECLARE_EVENT(CONNECTION_ERROR, wxCommandEvent);
#endif /* EVENTS_H */

