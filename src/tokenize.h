#ifndef _TOKENIZE_
#define _TOKENIZE_

int space_char(char *charac);

int non_space_char(char *charac);

char *word_start(char *str);

char *word_end(char *str);

int count_words(char *str);

int length_of_string(char *str);

char *copy_str(char *inStr, short len);

char **tokenized(char* str);

void print_tokens(char **tokens);

void free_tokens(char **tokens);

#endif
