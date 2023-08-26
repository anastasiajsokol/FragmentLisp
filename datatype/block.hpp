/**
 *      @file datatype/block.h
 *      @brief defines the Block datatype for generic organization of Tokens
 *      @author Anastasia Sokol
**/

#ifndef DATATYPE_BLOCK_H
#define DATATYPE_BLOCK_H

#include "token.hpp"

#include <type_traits>  // defines std::declval used to get the std::list iterator type
#include <list>         // defines std::list used to store tokens and blocks
#include <variant>      // defines std::varient used to store a mix of tokens and blocks in the same list

/**
 *  @brief defines a block of tokens which are logically grouped together and which may contain other blocks
**/
struct Block {
    // these horrors of types are used so that Block can become iterable by using std::list's iterator
    typedef decltype(std::declval<std::list<std::variant<Token, Block>>>().begin()) list_iterator_begin_type;
    typedef decltype(std::declval<std::list<std::variant<Token, Block>>>().end()) list_iterator_end_type;

    std::list<std::variant<Token, Block>> view; // store ordered collection or tokens and blocks that make up the block

    void append(std::variant<Token, Block> value);
    
    list_iterator_begin_type begin();
    list_iterator_end_type end();

    Token::TokenPosition position();
};

#endif