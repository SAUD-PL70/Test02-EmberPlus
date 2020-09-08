/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmberTree.h
 * Author: SAUD-DEVOPS
 *
 * Created on 5 de setembro de 2020, 20:01
 */

#include "Connection.h"

#ifndef EMBERTREE_H
#define EMBERTREE_H

class EmberTree {
public:
    EmberTree(Connection* conn, Server::Leds* leds);
    void Decode(void* buffer, uint32_t size);
    void EncodeKeepAlive();
    virtual ~EmberTree();
    
    bool hasResponse() { return hasresponse; }
    bool wasKeptAlive() { return keptalive; }
    void* getBuffer() { return (void*)buffer; }
    uint32_t getSize() { return size; }
private:
    Connection* connection;
    bool keptalive;
    bool hasresponse;
    uint32_t size;
    char* buffer;
    Server::Leds* leds;
};

#endif /* EMBERTREE_H */
