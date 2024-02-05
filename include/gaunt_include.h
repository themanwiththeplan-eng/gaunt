#include <stdlib.h>
#include <stdio.h>
#include <iostream>

namespace gaunt_include{
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

    void parseData(char c)
    {
      while (tokenType != STATE_ParseError && tokenType != STATE_EndOfData)
      {
        int c = fgetc(stdin);
        if (c == -1)
        {
            switch (tokenType)
            {
            case STATE_ParseNumber:
            case STATE_CheckEndOfString:
                printToken();
                //FIXME: a value of type "enum gaunt_include::<unnamed>" cannot be assigned to an entity of type "gaunt_include::TokenType"C/C++(513)
                // this error shouldn't be happening here, not sure why, maybe because using namespace?
                tokenType = STATE_EndOfData;
                break;
            case STATE_ParseString:
                std::cout << "Error: Unterminated string" << std::endl;
                tokenType = STATE_ParseError;
                break;
            case STATE_FindStartOfData:
            case STATE_FindStartOfToken:
            case STATE_FindDelimiter:
                tokenType = STATE_EndOfData;
                break;
            case STATE_ParseError:
            case STATE_EndOfData:
                break;
            }
        }
        switch (tokenType)
        {

        }

      }
    }
}
