#include <stdio.h>
#include <stdlib.h>
#include "mainUI.c"
#include "tokenize.h"

int space_char(char *charac){
  char *check = charac;
  char key = ' ';

  while(*check != '\n'){
    if(*check == key){
      return 1; //returns 1 if there was a space encountered
    }
    check++;
  }
  return 0; //returns 0 if there was no space encountered
}
//-----------------------------
int non_space_char(char *charac){
  char *check = charac;
  char key = ' ';

  while(*check++){
    if(*check == key){
      return 0; //returns 0 if there was a space encountered
    }
    check++;
  }
  return 1; //returns 1 if there was no space encountered
}
//-----------------------------
char *word_start(char *str){
  char *temp = str;
  if(*temp == '\0'){
    return 0;
  }

  while(*temp == ' '){
    temp++;
    if(++temp != ' '){
      return temp++;
    }
  }
  return temp;
}
//-----------------------------
char *word_end(char *str){
  if(*str == '\n'){ //check if string is empty
    return 0;
  }
  
  while(*str++){
    char *temp = str;
    ++temp;
    if(*temp == ' ' || *temp == '\n'){ //checks if string is empty 
      return str;
      exit(0); //may not need this
    }
  }
}
//-----------------------------
int count_words(char *str){
  int counter = 1;
  char *temp = word_start(str);

  while(*str++){ //iterates through the word
    if(*str == ' '){
      str++;
      if(*str != ' '){
	counter++;
      }
    }
  }
  return counter;
  exit(0);
}
//-----------------------------
int length_of_string(char *inStr, short len){
  int len = -1;
  while(*str++){
    len++;
  }
  return len;
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
      ptr[i] = inStr[i];
    }
    printf("String copied: ");
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
char** tokenize(char *str){
  int countwords = count_words(str);
  char **arraywords = (char **)malloc(sizeof(char*) * (++countwords));

  //filling array with words
  int dif = 0;
  for(int i = 0; i< countwords-1; i++){
    str = word_start(str);
    //find difference in length of string
    if(i != 0){
      if(*str++ == ' '){
	str++;
	str++;
      }
    }
    dif = word_end(str) - str;
    //adding new allocated string to the array
    arraywords[i] = copy_str(str,dif);
    str= word_end(str); //moves pointer to next word
  }
  arraywords[i] = '\0';
  return arraywords;  
}
//-----------------------------
void print_tokens(char **tokens){
  for(int i = 0; tokenz[i] != '\0'; i++){ //checks if there are characters when doing a for loop
    for(int j = 0; tokens[i][j] != '\0'; j++){ //checks if there are characters when doing a for loop
      printf("%c", tokens[i][j]); //prints tokens
    }
    printf("\n");
  }
}
