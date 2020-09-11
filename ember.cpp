/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ember.cpp
 * Author: josepva
 * 
 * Created on 9 de setembro de 2020, 09:33
 */

#define LIBEMBER_HEADER_ONLY
#include <Ember.hpp>
#include <util/StreamBuffer.hpp>
#include <dom/detail/ListContainer.hpp>
#include <glow/GlowCommand.hpp>
#include <glow/GlowNode.hpp>
#include <glow/GlowParameter.hpp>
#include <S101.hpp>
#include "ember.h"

Ember::Ember( Ember* parent, int id, std::string identifier, std::string description="" )
{
    this->parent = parent;
    this->id = id;
    this->identifier = identifier;
    this->description = description;
}

Ember::~Ember(){}

Root::Root( int id, std::string identifier, std::string description="" ) :
Ember(nullptr, id, identifier, description)
{
    hasresponse = false;
    keptalive = false;
    size = 0;
}

bool Root::Decode(void* buffer, uint32_t size)
{
    hasresponse = false;
    keptalive = false;
    size = 0;
    uint8_t* buffer_ptr = (uint8_t*) buffer;
    libember::util::OctetStream s101_stream;
    for(int i = 0; i < size; i++)
        s101_stream.append(buffer_ptr[i]);
    
    libs101::StreamDecoder<> decoder;

    libember::util::OctetStream glow_stream;
    decoder.read(s101_stream.begin(),
                 s101_stream.end(),
                 [&](auto it,auto end)
                 {
                     glow_stream.append(it,end);
                 });
    if(glow_stream.size()>0)
    {
        libember::dom::DomReader reader;
        libember::dom::Node* decoded_tree = reader.decodeTree( glow_stream, libember::glow::GlowNodeFactory::getFactory() );
        libember::glow::GlowRootElementCollection* decoded_tree_glow = dynamic_cast<libember::glow::GlowRootElementCollection*>( decoded_tree );

        if(decoded_tree_glow!=nullptr)
        {
            decoded_tree_glow->update();
            auto it = decoded_tree_glow->begin();
            auto end = decoded_tree_glow->end();
            for(;it!=end;it++)
            {
                libember::dom::Node& node = *(*it);
                libember::ber::Type type = libember::ber::Type::fromTag(node.typeTag());
                switch(type.value())
                {
                    case libember::glow::GlowCommand:
                        libember::glow::GlowCommand& glowcommand = dynamic_cast<libember::glow::GlowCommand&>(node);
                        break;
                    case libember::glow::GlowNode:
                        libember::glow::GlowNode& glownode = dynamic_cast<libember::glow::GlowNode&>(node);
                        if(glownode.number()<children.size())
                        {
                            return children[glownode.number()].Decode((void*)&node);
                        }
                        break;
                }
            }

            delete decoded_tree;
        }
    }
}

void Root::EncodeKeepAlive()
{
    
}
