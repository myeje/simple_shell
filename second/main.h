#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void prompt(void);
char *get_input(void);
void array_free(char **argv);
char **parse(char *input);
void exec(char **av);
int len(const char *str);
char *copy(char *destination, const char *original);
int _compare(char *s1, char *s2);
char *concate(char *dest, char *src);
void *_expan_mem(void *ptr, unsigned int pre_size, unsigned int add_size);
void give_linptr(char **lineptr, size_t *n, char *buff, size_t q);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
