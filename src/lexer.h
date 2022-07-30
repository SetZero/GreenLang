//
// Created by Sebastian on 30.07.2022.
//
#pragma once
#include <string>

enum class Token {
    tok_eof = -1,
    
    //commands
    tok_def = -2,
    tok_extern = -3,

    //primary
    tok_identifier = -4,
    tok_number = -5,
};

static std::string IdentifierStr;
static double NumVal;

static Token getToken();