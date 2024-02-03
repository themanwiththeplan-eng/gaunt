#include <stdlib.h>
#include <stdio.h>
#include <iostream>

namespace gaunt_parser{
    static char currentToken[4096];
    static size_t currentTokenLength;

    void addToken(char c)
    {
        if (currentTokenLength < sizeof(currentToken))
        {
            currentToken[currentTokenLength] = c;
        }
    }

    void printToken()
    {
        std::cout << currentToken << (int)currentTokenLength << std::endl;
    }

    typedef enum
    {
        STATE_FindStartOfData,
        STATE_FindStartOfToken,
        STATE_ParseNumber,
        STATE_ParseString,
        STATE_CheckEndOfString,
        STATE_FindDelimiter,
        STATE_ParseError,
        STATE_EndOfData
    } TokenType;

    TokenType tokenType = STATE_FindStartOfData; 
}
// TODO: implement #include tokenization and parsing here
