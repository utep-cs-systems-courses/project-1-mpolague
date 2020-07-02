#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenize.h"
//#include "tokenize.c"

int main(){
  List *history = init_history(); //initializing the linked list to store the history
  char word[20];
  int verifyingWhileLoop = 0;
  printf("Please enter a string or enter 'q' to quit the program\n");
  
  fgets(word, 20, stdin);
  int checkIfTrue = 0;
  
  while(checkIfTrue == 0){
   if(*word != 'q' && *word != '!'){
    printf("--------Calling tokenize------------\n");
    char **token = tokenized(word);
    printf("\n");
  
    printf("--------Calling print tokens--------\n");
    printf("The tokenized string is: \n");
    print_tokens(token);
 
    free_tokens(token); //will free tokens

    add_history(history,word); //will add it to the history
   }
   else if(*word == '!'){
     int enteredIndex = (int)(word[1] - '0');
     
     char *prev_str = get_history(history, enteredIndex);
     if(prev_str != NULL){ //will not go here if there is nothing in history
       printf("Item is:   ");
       printf(prev_str);
       printf("\n");
     }
   }
   else{
     printf("Program exited successfully.\n");
     checkIfTrue = 1; //will exit the while loop
   } 
  }
  printf("Input history: \n");
  print_history(history);

  //free linked list
  free_history(history);
  printf("Successfully cleared\n");
  return 0;
}
