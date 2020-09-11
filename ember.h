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
#include <vector>

#ifndef EMBER_H
#define EMBER_H

namespace ember {

class Node
{
    friend class Root;
    public:
        Node(Node* parent, int id, std::string identifier, std::string description);
        int getId();
        std::string getIdentifier();
        std::string getDescription();
        AddChild(Node* node);
protected:
        Node* Decode(void* glow_obj);
        void* Encode(int dir_mask=0);
};

class Root
{
    public:
        Root();
        /**
         * Add a child node to the structure
         * @param node  The node to be added
         */
        void AddChild(Node* node);
        /**
         * Decode a buffer with contents received from a ember pair
         * @param buffer    Pointer to the buffer with s101 message
         * @param size      Size in bytes of the buffer contents
         * @return          Return the pointer to lowest node which needs to give a response back to the ember pair or nullptr if no response is due
         */
        Node* Decode(void* buffer, uint32_t size);
        /**
         * If the last Decode method call was successful then the keptalive is true. False otherwise
         * @return 
         */
        bool isOk();
        /**
         * Encode a response to the ember pair
         * @param node      Pointer to the lowest node object that needs to give a response. Usually you need to give the response of the method Decode as this parameter
         * @return          true if the encoding process was succesful
         */
        bool Encode(Node* node=nullptr);
        /**
         * Get the buffer address of the last encoded data
         * @return The addrss of the last encoded data or nullptr if no data to be transmitted
         */
        void* getBuffer();
        /**
         * Get size of the contents in the buffer or 0 if no data needed to be transmitted
         * @return Size of the data buffer in bytes or 0 if no data to be transmitted
         */
        uint32_t getSize();
    private:
        const int MAX_BUFFER_SIZE=2048;
        bool ok;
        char buffer[MAX_BUFFER_SIZE];
        uint32_t size;
        std::vector<std::unique_ptr<Node>> children;
};
    
}
#endif /* EMBER_H */
