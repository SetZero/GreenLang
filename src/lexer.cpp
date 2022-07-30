//
// Created by Sebastian on 30.07.2022.
//

#include <string>
#include "lexer.h"

static Token getToken() {
    static char lastChar = ' ';

    //skip whitespace
    while(std::isspace(lastChar)) {
        lastChar = static_cast<char>(std::getchar());
    }

    if(std::isalpha(lastChar)) {//identifier/keyword: [a-zA-z][a-zA-Z0-9]*
        IdentifierStr = lastChar;
        while (std::isalnum(lastChar = static_cast<char>(std::getchar()))) {
            IdentifierStr += lastChar;
        }

        if(IdentifierStr == "def")
            return Token::tok_def;
        if(IdentifierStr == "extern")
            return Token::tok_extern;

        return Token::tok_identifier;
    }

    if(std::isdigit(lastChar) || lastChar == '.') { // Number: [0-9.]+
        std::string numStr;

        do {
            numStr += std::to_string(lastChar);
            lastChar = static_cast<char>(std::getchar());
        } while(std::isdigit(lastChar) || lastChar == '.');

        NumVal = std::strtod(numStr.c_str(), 0);

        return Token::tok_number;
    }

    if(lastChar == '#') { //comment
        do {
            lastChar = static_cast<char>(std::getchar());
        } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if(lastChar != EOF) return getToken();
    }

    if(lastChar == EOF) return Token::tok_eof;

    // if no known token is found return invalid token
    char thisChar = lastChar;
    lastChar = static_cast<char>(std::getchar());
    return static_cast<Token>(thisChar);
}