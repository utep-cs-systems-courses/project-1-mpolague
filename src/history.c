#include <stdio.h>
#include <stdlib.h>
#include "tokenize.h"
#include "history.h"

//initializing the linked list. This will keep track of the history
List *init_history(){
  List *hist = (List *)malloc(sizeof(List));
  hist->root = NULL;
}


//saves length of string
int str_length(char *str){
  int count;
  
  while(*str != '\0'){ //iterates through the list
    count++;
  }
  
  return count;
}

//adds a string to the end of the list
void add_history(List *hist, char *str){
  
  //creates pointer to a new item
  Item *new = (Item *)malloc(sizeof(Item));

  new->str = copy_str(str, str_length(str));
  new->next = NULL;

  if(hist->root == NULL){ //checks if it is empty
    hist->root == new_item; //new string is set to head and tail
    new->id = 1;
  }

  else{
    int prev_id = list-> root->id;
    hist->root->next = new_item; //next one is inserted
    hist->root = new_item; 
    new_item->id = prev_id+1; //set id
  }
}


//gets the string stored in the node where item->id == id
char *get_history(List *hist, int id){
  if(list->root->id < id){ //id must be within the list bounds
    printf("Error: Index out of bounds, Index must be less than %d\n", list->root->id);
    return NULL;
  }

  Item *current = hist->root;

  while(current->id != id){
    current = current->next;
  }

  return current->str;
}

void print_history(List *hist){
  Item *current = hist->root;

  while(current != NULL){
    printf(" %s ", current->str);
    current = current->next;
  }
  printf("\n");
}

void free_history(List *hist){
  Item *current = hist->root;
  Item *next; //will keep track of next

  while(current != NULL){
    next = current->next; //moves to next one
    free(current->str); 
    free(current);
    current=next; //current is set to something new
  }
}