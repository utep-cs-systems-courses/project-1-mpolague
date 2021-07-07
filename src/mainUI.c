#include <stdio.h>
#include <stdlib.h>
#include "tokenize.h"

int main(){
  char word[1000];
  int verifyingWhileLoop = 0;
  printf("Please enter a string or enter 'q' to quit the program\n");
  
  fgets(word, 1000, stdin);
  int checkIfTrue = 0;
  
  while(checkIfTrue == 0){
   if(*word != 'q' && *word != '!'){
    printf("--------Calling tokenize------------\n");
    //char **doubleArr = (char **)malloc(sizeof(char*) * (++countwords)); //creating space
    char **token = tokenized(word);
    printf("\n");
  
    printf("--------Calling print tokens--------\n");
    printf("The tokenized string is: \n");
    print_tokens(token);
 
    //free_tokens(token); //will free tokens

   }
   else{
     printf("Program exited successfully.\n");
     checkIfTrue = 1; //will exit the while loop
   } 
  }

  //free linked list
  //free_history(history);
  //printf("Successfully cleared\n");
  return 0;
}
