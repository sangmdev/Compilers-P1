#include <stdio.h>
#include "scanner.h"
#include "token.h"
#include <stdlib.h>
#include <string.h>
char *tokenNames[100] = {"ITER keyword", "VOID keyword", "VAR keyword", "RETURN keyword", "SCAN keyword", "PRINT keyword", "PROGRAM keyword", "COND keyword", "THEN keyword", "LET keyword", "INT keyword", "Equals operator", "Less than operator", "greater than operator", "colon delimiter", "plus operator", "minus operator", "asterick operator", "forwardslash delimiter", "percent operator", "period operator", "left paren delimiter", "right paren delimiter", "comma delimiter", "left brace delimiter", "right brace delimiter", "semicolon delimiter", "left bracket delimiter", "right bracket delimiter", "end of file delimiter", "identifier", "number", "error"};
struct token{
   enum tokenID tokenid; 
   char string[100][50]; 
   int lineNumber;
};
void testScanner(FILE *fileInput){
  //Start grabbing characters
  struct Token myToken;
  int lineNumber = 1;
  do{
     myToken = scanner(fileInput, &lineNumber);
     if(strcmp(tokenNames[myToken.tokenId], "error")== 0){
        printf("Error: exiting\n");
	exit(EXIT_FAILURE);
     }
     else{
        printf("Token: %s, Instance: %s, Line#: %i\n", tokenNames[myToken.tokenId],myToken.tokenString, myToken.lineNumber);
     }
  }while(!feof(fileInput));
}
