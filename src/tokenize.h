#ifndef _TOKENIZE_
#define _TOKENIZE_

int space_char(char c);

int non_space_char(char c);

char word_start(char *str);

char *word_terminator(char *word);

int count_words(char *str);

char *copy_str(char *inStr, short len);

char **tokenize(char* str);

void print_tokens(char **tokens);

void free_tokens(char **tokens);

#endif
