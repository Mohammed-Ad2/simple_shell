#ifndef S_SHELL_H
#define S_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/* Global environemnt */
extern char **environ;

char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *read_line(void);
char **splitter(char *str);
void free_2Darr(char **arr);
int _execute(char **cmd, char **av, int idx);
int count_tokens(const char *str);
void print_err(char *name, char *cmd, int idx);
char *_itoa(int n);
int _atoi(char *str);
int is_p_n(char *str);
void swap_str(char *str, int len);
char *_getenv(char *vaiable);
char *get_path(char *cmd);
int is_builtin(char *cmd);
void h_builtin(char **cmd, char **av, int *status, int index);
void exit_shell(char **cmd, char **av, int *status, int index);
void print_env(char **cmd, int *status);

#endif
