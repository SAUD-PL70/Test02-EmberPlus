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

#include "TestEmberTree.h"

#define LIBEMBER_HEADER_ONLY
#include <Ember.hpp>
#include <S101.hpp>

TestEmberTree::TestEmberTree(Connection* conn, Server::Leds* leds)
{
    connection = conn;
    keptalive = false;
    hasresponse = false;
    size = 0;
    buffer = nullptr;
    this->leds = leds;
}

void list_stream(libember::util::OctetStream& stream){
    std::cout << "Stream size: " << std::dec << stream.size() << std::endl;
    int counter = 0;
    std::string ascii = "";
    for(auto it = stream.begin(); it!=stream.end();)
    {
        if((counter%16)==0)
            std::cout << std::hex << std::setw(4) << std::setfill('0') << counter << " - ";
        ascii += (*it>=32 && *it<=126 ? *it : '.');
        std::cout << std::hex<< std::setw(2) << int(*it) << " ";
        it++;
        if((counter%16)==15 || it==stream.end())
        {
            std::cout << ascii << std::endl;
            ascii = "";
        }
        counter++;
    }
}

void TestEmberTree::Decode(void* buffer, uint32_t size)
{
    uint8_t* received_buffer = (uint8_t*)buffer;
    libember::util::OctetStream input_buffer;
    libember::util::OctetStream decoded_buffer;
    
    //Convert a void* buffer to octetstream
    for(int i=0;i<size;i++)
        input_buffer.append(received_buffer[i]);
    
    libs101::StreamDecoder<> decoder;
    decoder.read(input_buffer.begin(),input_buffer.end(),[&](auto it, auto end){
       decoded_buffer.append(it,end);
    });
    
    list_stream(decoded_buffer);

    //Verifica se a mensagem recebida é um comando de KeepAliveRequest
    if(decoded_buffer.size()==4){
        auto it = decoded_buffer.begin();
        if(*it++==0){
            if(*it++==0x0e)
            {
                if(*it==1 || *it==2)
                {
                    uint8_t command = *it++;
                    if(*it==1)
                    {
                        if(command == 1)
                        {
                        //Recebemos uma mensagem de KeepAliveRequest
                        //Vamos devolver a resposta
                            libs101::StreamEncoder<> encoder;
                            encoder.encode(0x0);
                            encoder.encode(0x0e);
                            encoder.encode(0x2);
                            encoder.encode(0x1);
                            encoder.finish();
                            libember::util::OctetStream encoded_stream;
                            encoded_stream.append(encoder.begin(),encoder.end());
                            if(this->buffer!=nullptr)
                                delete this->buffer;
                            this->buffer = new char[encoded_stream.size()];
                            auto it = encoded_stream.begin();
                            auto end = encoded_stream.end();
                            int pos = 0;
                            for(;it!=end;it++)
                            {
                                this->buffer[pos] = *it;
                            }   
                            hasresponse =  true;
                            keptalive = false;
                        }
                        else
                        {
                        //Recebemos uma mensagem de KeepAliveResponse
                        //Atualizara flag de status
                            keptalive = true;
                            hasresponse = false;
                        }
                        
                    }
                }
            }
                
        }
    }
//    
//    if(decoded_buffer.size()!=0)
//    {
//        libember::dom::DomReader reader;
//        libember::dom::Node* decoded_tree = reader.decodeTree(decoded_buffer,libember::glow::GlowNodeFactory::getFactory());
//        
//        libember::glow::GlowRootElementCollection* decoded_tree_glow = dynamic_cast<libember::glow::GlowRootElementCollection*>(decoded_tree);
//        decoded_tree_glow->update();
//        
//        auto it = decoded_tree_glow->begin();
//        auto end = decoded_tree_glow->end();
//        for(;it!=end;it++)
//        {
//            libember::dom::Node& node = *it;
//            
//            libember::ber::Type type = libember::ber::Type::fromTag(node.typeTag());
//            if(type.isApplicationDefined())
//            {
//                switch(type.value())
//                {
//                    case libember::glow::GlowType::Node:
//                        //@todo
//                        break;
//                    case libember::glow::GlowType::Command:
//                        libember::glow::GlowCommand& command = dynamic_cast<libember::glow::GlowCommand&>(node);
//                        switch(command.number())
//                        {
//                            case libember::glow::CommandType::GetDirectory:
//                                break;
//                        }
//                        break;
//                }
//            }
//        }
//
//    }
}

void TestEmberTree::EncodeKeepAlive()
{
    
}

TestEmberTree::~TestEmberTree()
{
    if(buffer!=nullptr)
        delete buffer;
}
