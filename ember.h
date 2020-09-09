/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ember.h
 * Author: josepva
 *
 * Created on 9 de setembro de 2020, 09:33
 */
#include <list>

#ifndef EMBER_H
#define EMBER_H

class Ember {
public:
    /**
     * Constructor of the virtual class Ember
     * @param parent        The parent Ember object. If there is no parent it is nullptr
     * @param id            The ember id of the object
     * @param identifier    The identifier string of the obj
     * @param description   The description string of the object
     */
    Ember( Ember* parent, int id, std::string identifier, std::string description="" );
    /**
     * Gets the parent ember object, which is the Ember object that contains this object 
     * @return  The pointer to the parent object or nullptr if this object is not contained by other Ember object
     */
    Ember* getParent() { return parent; }
    /**
     * Gets the ember id number
     * @return The ember id number
     */
    int getId() { return id; }
    /**
     * Gets the identifier string of the object
     * @return The identifier string of the object
     */
    std::string getIdentifier() { return identifier; }
    /**
     * Gets the description string of the object
     * @return the description string of the object
     */
    std::string getDescription() { return description; }
    /**
     * The destructor of the Ember object
     */
    virtual ~Ember();
protected:
    virtual void* getEmberObj() = 0;
    virtual bool Decode( void* obj );
    virtual void* getNode();
    virtual void* Encode();
private:
    Ember* parent;
    int id;
    std::string identifier;
    std::string description;
};

class pBool;
class Node : public Ember {
public:
    Node( Ember* parent, int id, std::string identifier, std::string description="" );
    virtual bool Decode( void* obj );
    virtual void* getEmberObj();
    virtual void* getNode();
    virtual void* Encode();
private:
    std::list<Node> children;
};

class Root : public Ember {
public:
    Root( int id, std::string identifier, std::string description="" );
    bool Decode(void* buffer, uint32_t size);
    void AddNode(Node& node);
    void EncodeKeepAlive();
    void* getBuffer() { return (void*)&buffer; }
    uint32_t getSize() { return size; }
    bool hasResponse() { return hasresponse; }
    bool keptAlive() { return keptalive); }
private:
    std::list<Node> nodes;
    bool hasresponse;   //Indicates that the buffer contains a ember message ready to be sent
    bool keptalive;     //True every time a ember message was succesfully decoded, false after EncodeKeepAlive()
    char buffer[1024];  //Max ember message size
    uint32_t size;      //Size of the contents in the buffer
};

#endif /* EMBER_H */
