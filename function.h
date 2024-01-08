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
char *strcat(char *dest, char *src);
int strlen(char *s);
int strcmp(char *s1, char *s2);


#endif
