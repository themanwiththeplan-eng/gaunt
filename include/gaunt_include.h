#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//TODO: maybe just rewrite this entire thing in c honestly and use https://github.com/tsoding/flag.h/blob/master/flag.h as reference

//BUG: some issue with function definition ODR rules, have to fix this going forward
namespace gaunt_include {
static char currentToken[4096];
static size_t currentTokenLength;

void addToken(char c) {
  if (currentTokenLength < sizeof(currentToken)) {
    currentToken[currentTokenLength] = c;
  }
}

void printToken() {
    printf('%s', c);
}


enum TokenType {
  STATE_FindStartOfData,
  STATE_FindStartOfToken,
  STATE_ParseNumber,
  STATE_ParseString,
  STATE_CheckEndOfString,
  STATE_FindDelimiter,
  STATE_ParseError,
  STATE_EndOfData
};

TokenType token = STATE_FindStartOfData;

void parseData(char c) {
  while (token != STATE_ParseError && token != STATE_EndOfData) {
    int c = fgetc(stdin);
    if (c == -1) {
      switch (token) {
      case STATE_ParseNumber:
      case STATE_CheckEndOfString:
        printToken();
        // FIXME: a value of type "enum gaunt_include::<unnamed>" cannot be
        // assigned to an entity of type "gaunt_include::TokenType"C/C++(513)
        //  this error shouldn't be happening here, not sure why, maybe because
        //  using namespace?
        token = STATE_EndOfData;
        break;
      case STATE_ParseString:
        std::cout << "Error: Unterminated string" << std::endl;
        token = STATE_ParseError;
        break;
      case STATE_FindStartOfData:
      case STATE_FindStartOfToken:
      case STATE_FindDelimiter:
        token = STATE_EndOfData;
        break;
      case STATE_ParseError:
      case STATE_EndOfData:
        break;
      }
    }
    switch (token) {}
  }
}
} // namespace gaunt_include
