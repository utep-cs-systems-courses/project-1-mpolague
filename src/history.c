#include <stdio.h>
#include <stdlib.h>
#include "tokenize.h"
#include "history.h"

List *init_history(){
  LIst *list = (List *)malloc(sizeof(List));
  list->root = NULL;
}

int str_length(char *str){
  int count;
  while(*str != '\0'){
    count++;
  }
  return count;
}

void add_history(List *list, char *str){
  Item *new_item = (Item *)malloc(sizeof(Item));

  new_item->str = copy_str(str, str_length(str));
  new_item->next = NULL;

  if(list->root == NULL){
    list->root == new_item;
    new_item->id = 1;
  }

  else{
    int prev_id = list-> root->id;
    list->root->next = new_item;
    list->root = new_item;
    new_item->id = prev_id+1;
  }
}

char *get_history(List *list, int id){
  if(list->root->id < id){
    printf("Error: INdex out of bounds, Index must be less than %d\n", list->root->id);
    return NULL;
  }

  Item *current = list->root;

  while(current->id != id){
    current = current->next;
  }

  return current->str;
}

void print_history(List *list){
  Item *current = list->root;

  while(current != NULL){
    printf(" %s ", current->str);
    current = current->next;
  }
  printf("\n");
}

void free_history(List *list){
  Item *current = list->root;
  Item *next;

  while(current != NULL){
    next = current->next;
    free(current->str);
    free(current);
    current=next;
  }
}
