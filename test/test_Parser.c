#include <stdio.h>
#include "unity.h"
#include "Parser.h"
#include "CreateToken.h"
#include "mock_Token.h"
#include "mock_Tokenizer.h"

// Global variable(s) used by getToken(), peepToken(), and advanceToken()
Token **tokenTable = NULL;
//int tableIndex;

Token *fake_getToken(Tokenizer *tokenizer, int numOfCalls) {
  // Fake getToken here...
  printf("getToken() get called...\n");
  if(*tokenTable)
    return *tokenTable++;
  return *tokenTable;
}

Token *fake_peepToken(Tokenizer *tokenizer, int numOfCalls) {
  // Fake peepToken here...
  printf("peepToken() get called...\n");
  return *tokenTable;
}

Token *fake_advanceToken(Tokenizer *tokenizer, int numOfCalls) {
  // Fake advanceToken here...
  printf("advanceToken() get called...\n");
  return fake_getToken(tokenizer, numOfCalls);
}

/**
 * Initialize the fakery
 */
void initTokenizer(Token *table[]) {
  tokenTable = table;
//  tableIndex = 0;
}


void setUp(void) {
  getToken_StubWithCallback(fake_getToken);
  peepToken_StubWithCallback(fake_peepToken);
  advanceToken_StubWithCallback(fake_advanceToken);
}

void tearDown(void) {
  tokenTable = NULL;
}


void test_parse_given_xxx_should_return_yyy(void) {
  Tokenizer tokenizer;
  Token *table[] = {
    (Token *)createInteger(30),
    (Token *)createOperator("+"),
    (Token *)createInteger(40),
    NULL
  };
  initTokenizer(table);

  parse(&tokenizer);
}


void test_parse_given_aaa_should_return_bbb(void) {
  Tokenizer tokenizer;
  Token *table[] = {
    (Token *)createInteger(60),
    (Token *)createOperator("*"),
    (Token *)createInteger(234),
    (Token *)createOperator("-"),
    (Token *)createInteger(6),
    NULL
  };
  initTokenizer(table);

  parse(&tokenizer);
}
