#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
char prompt(void);
int len(const char *str);
char *copy(char *destination, const char *original);
int _compare(char *s1, char *s2);
char *concate(char *dest, char *src);
char **parse(char *input);
int exec(char **argv);
char *path_finder(char *command);
extern char **environ;
void array_free(char **argv);
void change_directory(char **argv);
int builtin_struct(void);
int shell_env(char **argv);
int shell_exit(char **argv);
int shell_cd(char **argv);
void full_path(char *fp, char *d, char *cmd);
int exec_external(char **argv);
char *read_cmd(void);
void non_interactive_mode(void);
char *non_int_read(void);
ssize_t _getline(char **ptr, size_t *n, FILE *stream);
void *_allocate(void *buffer, unsigned int size_prev, unsigned int size_new);
void buffer_assign(char **ptr, char *str, size_t *a, size_t b);
void execute_from_file(char *filename);
int _atoi(char *a);
#endif
