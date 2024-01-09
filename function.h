#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "shell.h"

extern char **environ;

void binExit(shell_t *str, char **args);
void binEnv(shell_t *str, char **args);
int buildins(shell_t *str, char **args);
int verifybuildin(shell_t *str, char **args);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void freeMemory(void *ptr);
void freeMemoryPointer(void **ptr);
int manageNumbers(shell_t *str, char *argument);
void fetchFullEnv(void);
int systemfunction(shell_t *str, char **args);
int displayer(char *message);
int ErrorDisplay(char *message);
int putToFD(char *message, int fil_d);
int i_File(char *filename);
void an_issue(shell_t *mytype);
void evaluation(char **args, shell_t *mytype, char *buffer);
char *messageSelect(shell_t mytype);
char *stringified(int numbe);
char *_strcopy(char *dest, char *src);
char *wordMerge(char *w1, char *w2, char *w3, const char *del);
char *_strdog(char *dest, char *src);
int _strlem(char *s);
#endif
