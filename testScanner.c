#include <stdio.h>
#include "scanner.h"

void testScanner(char *fileName, FILE **fileInput){
  printf("Hello from testScanner. \n");
  char myChar;
  *fileInput = fopen(fileName, "r");
  //FILE opened 
  //Start grabbing characters
  while((fscanf(*fileInput,"%c", &myChar)) != EOF){
     printf("my char is: %c\n", myChar);
  }
}
