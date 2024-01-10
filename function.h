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

extern char **anvir;

void binExit(shell_t *str, char **args);
void binEnv(shell_t *str, char **args);
int buildins(shell_t *str, char **args);
int verifybuildin(shell_t *str, char **args);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strbup(char *str);
void freeMemory(void *ptr);
void freeMemoryPointer(void **ptr);
int manageNumbers(shell_t *str, char *argument);
void fetchFullEnv(void);
int systemfunction(shell_t *str, char **args);
int displayer(char *message);
int errorDisplay(char *message);
int putToFD(char *message, int fil_d);
int writeFDcharacters(char cha, int fil_d);
int i_File(char *filename);
void an_issue(shell_t *mytype);
char *_strcpy(char *dest, char *src);
void evaluate(char **args, shell_t *mytype, char *buffer);
char *exchange(shell_t *mytype, int *id, char *word);
char *stringify(int numbe);
char *subEnv(shell_t *mytype, char *envi_var);
char *selectMessage(shell_t mytype);
char *wordsMerg(char *w1, char *w2, char *w3, const char *delx);
int writeCharacter(char cha, int fil_d);
void evaluation(char **args, shell_t *mytype, char *buffer);
void lookFullEnv(void);
char *messageSelect(shell_t mytype);
char *stringified(int numbe);
char *_strcopy(char *dest, char *src);
char *wordMerge(char *w1, char *w2, char *w3, const char *del);
char *_strdog(char *dest, char *src);
int _strlem(char *s);
char *sunAnv(shell_t *mytype, char *envi_var);
void error_addition(shell_t *mytype, char *more);
int CurrentDir(char *command, char **argu, char *buff, shell_t *mytype);
char *chosen(char *dirname, shell_t *mytype);
void japa(char *cmd, char **argu, shell_t *mytype, char *buffer);
char *envGet(const char *variable);
char *exchanging(shell_t *mytype, int *id, char *word);
int characterWriter(char character);
int numbering(int num);
void begining(shell_t *mytype);

#endif
