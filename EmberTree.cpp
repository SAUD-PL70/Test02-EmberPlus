/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmberTree.cpp
 * Author: SAUD-DEVOPS
 * 
 * Created on 5 de setembro de 2020, 20:01
 */

#include "EmberTree.h"

#define LIBEMBER_HEADER_ONLY
#include <Ember.hpp>
#include <s101.hpp>

EmberTree::EmberTree(Connection* conn, Server::Leds* leds)
{
    connection = conn;
    keptalive = false;
    hasresponse = false;
    size = 0;
    buffer = nullptr;
    this->leds = leds;
}

void EmberTree::Decode(void* buffer, uint32_t size)
{
    uint8_t* received_buffer = (uint8_t*)buffer;
    libember::util::OctetStream received_data;
    
    //Convert a void* buffer to octetstream
    for(int i=0;i<size;i++)
        received_data.append(received_buffer[i]);
    
}

void EmberTree::EncodeKeepAlive()
{
    
}

EmberTree::~EmberTree()
{
    
}
