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
void array_free(char **argv);
void change_directory(char **argv);
#endif
