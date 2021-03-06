#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"

int space_char(char *charac){
  char *check = charac;
  char key = ' ';

  while(*check != '\n'){
    if(*check == key){ //checks if its a space
      return 1; //returns 1 if there was a space encountered
    }
    check++; //moves pointer
  }
  return 0; //returns 0 if there was no space encountered
}
//-----------------------------
int non_space_char(char *charac){
  char *check = charac;
  char key = ' ';

  while(*check++){
    if(*check == key){ //checks if there was a space
      return 0; //returns 0 if there was a space encountered
    }
    check++; //moves pointer
  }
  return 1; //returns 1 if there was no space encountered
}
//-----------------------------
char *word_start(char *str){
  char *temp = str; //saving the string in a temporary value
  if(*temp == '\0'){
    return 0;
  }

  while(*temp == ' '){ //*checks if it is a space so it can iterate through the rest of the string
    temp++; //will go to the next character in the string
    
    if(space_char(temp) == 0){
      return temp; //if no space encountered it returns the character found
    }
    
    char *checking = temp;
    
    checking++; //will go to the next character in the string
    if(space_char(checking) == 0){ //*checking != ' ' -- checking if it is a non-space
      return checking++; //will return the next character of a new word encountered
    }
  }
  return temp;
}
//-----------------------------
char *word_end(char *str){
  if(*str == '\n'){ //check if string is empty
    return 0;
  }
  
  while(*str++){ //will iterate through the string
    char *temp = str; 
    ++temp; //will check the character that is after str
    if(*temp == ' ' || *temp == '\n'){ //checks if string is empty 
      return str;
      exit(0); //may not need this
    }
  }
  return str;
}
//-----------------------------
int count_words(char *str){
  int counter = 1;
  char *temp = word_start(str); //gets the first character encountered

  while(*str++){ //iterates through the word
    if(*str == ' '){ //checks if it is a space
      str++; 
      if(*str != ' '){ //checks if it is not a space
	counter++; //if not a space, it counts a new word
      }
    }
  }
  return counter;
  exit(0);
}
//-----------------------------
int length_of_string(char *str){
  int length = -1;
  while(str++){ //iterates through the string
    length++; //adds to counter
  }
  return length;
  exit(0);
}
//-----------------------------
char *copy_str(char *inStr, short len){
  char *ptr = (char*) malloc ((len)* sizeof(char));

  if(ptr == NULL){ //memory allocation failed
    printf("Could not allocate memory\n");
  }
  else{
    printf("Memory reallocation successful.\n");

    for(int i = 0; i < len+1; i++){
      ptr[i] = inStr[i]; //copying the passed string into ptr
    }
    printf("String copied: "); //just making sure that the word passed was copied successfully
    for(int i = 0; i < len+1; i++){
      printf("%c", ptr[i]);
    }
    printf("\n");
    printf("----\n");
  }

  while(*ptr == ' '){ //this is just in case there are no spaces detected
    ptr++; //iterates through the word until there are no spaces
  }
  return ptr;
			     
}
//-----------------------------
char** tokenized(char *str){
  int countwords = count_words(str);
  char **doubleArr = (char **)malloc(sizeof(char*) * (++countwords)); //creating space

  //filling array with words
  int dif = 0;
  int i;
  for(i = 0; i< countwords-1; i++){
    str = word_start(str); //saves the first character encountered
    //find difference in length of string
    if(i != 0){
      if(*str++ == ' '){ //I did not use helpers because it was easier for me to understand 
	str++;
	str++;
      }
    }
    dif = word_end(str) - str;
    //adding new allocated string to the array
    doubleArr[i] = copy_str(str,dif);
    str= word_end(str); //moves pointer to next word
  }
  doubleArr[-1] = '\0';
  return doubleArr;  
}
//-----------------------------
void print_tokens(char **tokens){
  for(int i = 0; tokens[i] != '\0'; i++){ //checks if there are characters when doing a for loop
    for(int j = 0; tokens[i][j] != '\0'; j++){ //checks if there are characters when doing a for loop
      printf("%c", tokens[i][j]); //prints tokens
    }
    printf("\n");
  }
  printf("working");
  return;
}

//void free_tokens(char **tokens){
//  for(int i = 0; tokens[i] != NULL; i++){ //iterates and checks if NULL, if not, it frees tokens
//    free(tokens[i]);
//  }
  //free(tokens[0]);
//}
