#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void prompt(void);
int len(const char *str);
char *copy(const char *original);
int _compare(char *s1, char *s2);
void parse(char *input, char ***argv);
void exec(char **argv);
char *path_finder(char *command);
#endif
