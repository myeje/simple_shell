#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void prompt(void);
int len(const char *str);
char *copy(char *destination, const char *original);
int _compare(char *s1, char *s2);
char *concate(char *dest, char *src);
void parse(char *input, char ***argv);
void exec(char **argv);
char *path_finder(char *command);
void shell_env(void);
extern char **environ;
void *_expan_mem(void *ptr, unsigned int prev_size, unsigned int add_size);
void give_linptr(char **lineptr, size_t *n, char *buff, size_t q);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void full_path(char *fp, char *d, char *cmd);
void array_free(char **argv);
#endif
