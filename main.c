#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "testScanner.h"
int main(int argc, char *argv[]){
   if(argc > 2){
      fprintf(stderr,"ERROR: Too many arguments\n");
      exit(EXIT_FAILURE);
   }
   FILE *fp;
   char newBase[100];
   if(argc == 2){
      strncpy(newBase, argv[1], sizeof(newBase));
      char *base = argv[1];
      char *baseTag = ".sp19";
      strncat(base, baseTag, 5);
      fp = fopen(base, "r");
      if(fp == NULL){
         fprintf(stderr, "ERROR: %s\n", strerror(errno));
	 exit(EXIT_FAILURE);
      }
      testScanner(fp);
      fclose(fp);
   }//END OF argc == 2
   else if(argc == 1){
      fp = stdin;
      testScanner(fp);
      fclose(fp);
   } 
   return 0;
}
