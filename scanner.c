#include <stdio.h>
#include "token.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int key;
	enum tokenID tokenInstanceType;
}tokenMap;

//Final State Lookup Table
tokenMap tokens[21] = {
   {1001, ID_TK},
   {1002, INTEGER_TK},
   {1003, EQUALS_TK},
   {1004, LESSTHAN_TK},
   {1005, GREATERTHAN_TK},
   {1006, COLON_TK},
   {1007, PLUS_TK},
   {1008, MINUS_TK},
   {1009, ASTERICK_TK},
   {1010, FORWARDSLASH_TK},
   {1011, PERCENT_TK},
   {1012, PERIOD_TK},
   {1013, LEFTPAREN_TK},
   {1014, RIGHTPAREN_TK},
   {1015, COMMA_TK},
   {1016, LEFTBRACKET_TK},
   {1017, RIGHTBRACKET_TK},
   {1018, SEMICOLON_TK},
   {1019, LEFTBRACE_TK},
   {1020, RIGHTBRACE_TK},
   {1021, EOF_TK}
};

struct Token keyword[12] = {
   {ITER_TK, "iter", 0},
   {VOID_TK, "void", 0},
   {VAR_TK, "var", 0},
   {RETURN_TK, "return", 0},
   {SCAN_TK, "scan", 0},
   {PRINT_TK, "print", 0},
   {PROGRAM_TK, "program", 0},
   {COND_TK, "cond", 0},
   {THEN_TK, "then", 0},
   {LET_TK, "let", 0},
   {INT_TK, "int", 0}
};


struct columnPair{
   int key;
   int value;
};
struct columnPair columnLookup[23] = {
  {'=', 4},
  {'<', 5},
  {'>', 6},
  {':', 7},
  {'+', 8},
  {'-', 9},
  {'*', 10},
  {'/', 11},
  {'%', 12},
  {'.', 13},
  {'(', 14},
  {')', 15},
  {',', 16},
  {'{', 17},
  {'}', 18},
  {';', 19},
  {'[', 20},
  {']', 21}
};

//FSA table
int fsaTable[21][23] = {
   {-1, 1, 2, 0 ,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1021},
   {1, 1, 1, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 10001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001},
   {1002, 1002, 2, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002},
   {1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003},
   {1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004},
   {1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005},
   {1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006},
   {1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007},
   {1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008},
   {1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009},
   {1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010},
   {1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011},
   {1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012},
   {1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013},
   {1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014},
   {1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015},
   {1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016},
   {1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017},
   {1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018},
   {1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019},
   {1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020}
};

struct Token scanner(FILE *input, int *lineNumber){
   struct Token myToken;
   int lookahead;
   int currentState = 0;
   int nextState = 0;
   int i = 0;
   int columnNumber = 0;
   char *builtString = malloc(9);
   char *builtCharString = malloc(2);
   int lookupFlag = 0;
   myToken.tokenId = 999;
   myToken.tokenString = NULL;
   myToken.lineNumber = 999;
   while(currentState < 1000 && currentState > -1){
      if(lookahead == '\n'){
           (*lineNumber)++;
      }
      lookahead = fgetc(input);
      printf("look:%d\n", lookahead);
        if(lookahead == '&'){               //comment start
           while (lookahead != '\n'){      //ignore input until new line
	      lookahead = fgetc(input);
	   }
	   lineNumber++;
	   lookahead = fgetc(input);
        }
       //map char to column #

      for(i = 0; i < 16; i++){                 //test for all the operators and delimiters
         if(columnLookup[i].key == lookahead){
            columnNumber = columnLookup[i].value;
	    lookupFlag = 1;
         }
      }
      if(lookupFlag == 0){ //check if column has already been matched
         if(isupper(lookahead)){
             columnNumber = 0;
         } else if(islower(lookahead)){
             columnNumber = 1;
         } else if(isdigit(lookahead)){
             columnNumber = 2;
         } else if(isspace(lookahead)){
             columnNumber = 3;
         } else if(lookahead == EOF){
             columnNumber = 22;
         } else{
             printf("ERROR: invalid input.\n");
         }
      }

      sprintf(builtCharString, "%c", lookahead);
      nextState = fsaTable[currentState][columnNumber];
      if(nextState > 1000 || nextState == 1021){ //if final state or eof
         if(nextState == 1021){ //eof case
	    myToken.tokenId = EOF_TK;
	    myToken.tokenString = "EOF";
	    myToken.lineNumber = *lineNumber;
	    return myToken;
	 }else if(nextState > 1000){ //final state, have to check tokenMap
	    for(i = 0; i < 21; i++){
	       if(tokens[i].key == nextState){ //matched our token
	          if(nextState == 1001){  //if id token
		     //lookup word in keyword table
		     int j = 0;
		     for(j = 0; j < 11; j++){
		        if(strcmp(builtString, keyword[j].tokenString) == 0){
                           myToken.tokenId = keyword[j].tokenId;
			   myToken.lineNumber = *lineNumber;
			   myToken.tokenString = builtString;
			   return myToken;
			}
		     }
		     //if doesnt match any keywords, return identifier
		     myToken.tokenId = tokens[i].tokenInstanceType;
		     myToken.lineNumber = *lineNumber;
		     myToken.tokenString = builtString;
		     return myToken;
	          }else{
	             myToken.tokenId = tokens[i].tokenInstanceType;
		     myToken.lineNumber = *lineNumber;
		     myToken.tokenString = builtString;
		     return myToken;
		  }
		}// END OF ID Token checks
	    }
	  }else{//END of final state checks
	     myToken.tokenId = ERROR_TK;
	     myToken.tokenString = "Error"; 
	     myToken.lineNumber = *lineNumber;
	     return myToken;
       }// end of final state or eof
      }else{ //If not final state or eof ~> has to be transitional state
        char value = (char)lookahead;  //change ascii to character
	if(!isspace(value)){
	    strcat(builtString, builtCharString);
	    if(strlen(builtString) > 8){
	       printf("Scanner Error: Identifier or Number exceeds length of 8: %s\n", builtString);
	       myToken.tokenId = ERROR_TK;
	       myToken.lineNumber = *lineNumber;
	       myToken.tokenString = "Length";
	       return myToken;
	    }
	}
        //count lines//

	currentState = nextState;
      }
   }//end of while loop
   myToken.tokenId = ERROR_TK;
   myToken.tokenString = "Scanner ERROR: scanner did not work!";
   myToken.lineNumber = *lineNumber;
   return myToken;
}
