#ifndef TOKEN_H
#define TOKEN_H

//Token is a triplet{tokenID, tokenInstance, line#}
//tokenId can be enumeration
//tokenInstance can be string or reference to string table
//triplet can be struct

enum tokenID{
   //keywords
   ITER_TK,
   VOID_TK,
   VAR_TK,
   RETURN_TK,
   SCAN_TK,
   PRINT_TK,
   PROGRAM_TK,
   COND_TK,
   THEN_TK,
   LET_TK,
   INT_TK,
   //Operators and Delimiters
   EQUALS_TK,
   LESSTHAN_TK,
   GREATERTHAN_TK,
   COLON_TK,
   PLUS_TK,
   MINUS_TK,
   ASTERICK_TK,
   FORWARDSLASH_TK,
   PERCENT_TK,
   PERIOD_TK,
   LEFTPAREN_TK,
   RIGHTPAREN_TK,
   COMMA_TK,
   LEFTBRACE_TK,
   RIGHTBRACE_TK,
   SEMICOLON_TK,
   LEFTBRACKET_TK,
   RIGHTBRACKET_TK,
   //OTHERS
   EOF_TK,
   ID_TK,
   INTEGER_TK,
   ERROR_TK
};

struct Token{
   enum tokenID tokenId;
   char tokenString[100];
   int lineNumber;
}; //End of Token Structure

#endif
