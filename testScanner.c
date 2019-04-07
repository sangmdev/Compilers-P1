#include <stdio.h>
#include "scanner.h"
#include "token.h"
#include <stdlib.h>
#include <string.h>
char *tokenNames[100] = {"ITER keyword", "VOID keyword", "VAR keyword", "RETURN keyword", "SCAN keyword", "PRINT keyword", "PROGRAM keyword", "COND keyword", "THEN keyword", "LET keyword", "INT keyword", "Equals operator", "Less than operator", "Greater than operator", "Colon delimiter", "Plus operator", "Minus operator", "Asterick operator", "Forwardslash delimiter", "Percent operator", "Period operator", "Left paren delimiter", "Right paren delimiter", "Comma delimiter", "Left brace delimiter", "Right brace delimiter", "Semicolon delimiter", "Left bracket delimiter", "Right bracket delimiter", "End of File delimiter", "Identifier", "Number", "ERROR"};
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
