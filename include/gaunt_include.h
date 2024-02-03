#include <stdlib.h>
#include <stdio.h>
#include <iostream>

static char currentToken[4096];
static size_t currentTokenLength;

void addToken (char c){
    if (currentTokenLength < sizeof(currentToken)) {
        currentToken[currentTokenLength] = c;
    }
}

void printToken(){
    std::cout << currentToken << (int)currentTokenLength << std::endl;
}

typedef enum {
    TOKEN_TYPE_NONE,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_PUNCTUATOR,
    TOKEN_TYPE_PARSE_ERROR
} TokenType;

// TODO: implement #include tokenization and parsing here
