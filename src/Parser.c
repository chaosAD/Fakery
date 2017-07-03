#include <stdio.h>
#include "Parser.h"
#include "Token.h"
#include "CreateToken.h"

void tokenDump(Token *token);

// Unit Under Test (UUT)
Token *parse(Tokenizer *tokenizer) {
  Token *token;

  while((token = getToken(tokenizer)) != NULL) {
    tokenDump(token);
  }
  tokenDump(token);

//  tokenDump(peepToken(tokenizer));
//  tokenDump(advanceToken(tokenizer));
}

void tokenDump(Token *token) {
  if(token == NULL) {
    printf("token is NULL\n");
    return;
  }
  switch(token->type) {
  case TOKEN_INTEGER_TYPE:
    printf("token: TOKEN_INTEGER_TYPE, value: %d\n", ((IntegerToken *)token)->value);
    break;
  case TOKEN_OPERATOR_TYPE:
    printf("token: TOKEN_OPERATOR_TYPE, symbol: %s\n", ((OperatorToken *)token)->str);
    break;
  default:
    printf("Error: Unknown token\n");
    break;
  }
}
