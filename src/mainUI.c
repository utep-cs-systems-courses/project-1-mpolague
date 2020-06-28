#include "tokenize.c"
#include <stdio.h>
#include "history.h"
#include <stdlib.h>

int main(){
  char name[20];
  fgets(name, 20, stdin);

  printf("--------Calling *word_start--------\n");
  char *str=&name[0]; //points at first character
  char *starting = word_start(str);
  printf("letter: %c\n", *starting);
  printf("value: %d\n", *starting);

  printf("--------Calling *word_end--------\n");
  char *ending = word_end(str);
  printf("letter: %c \n", *ending);
  printf("letter: %d \n", *ending);
  printf("\n");

  printf("-------Calling count_words-------\n");
  int counted = count_words(str);
  printf("The number of words counted were: %d\n", counted);
  printf("\n");

  printf("--------Calling copy_string--------\n");
  int length = length_of_string(str);
  char *copied = copy_str(str, length);
  printf("\n");

  printf("--------Calling print tokens--------\n");
  printf("The tokenized string is: \n");
  print_tokens(token);
}
