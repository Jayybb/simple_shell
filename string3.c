#include "shell.h"
#include "function.h"
/**
 * strcmp - compare two strings in a buffer
 * @s1: first string
 * @s2: second string
 *
 * Return: 0
 */
int strcmp(char *s1, char *s2)
{
int i;
int j = 0;

for (i = 0; s1[i] != '\0' && j == 0; i++)
{
j = s1[i] - s2[i];
}

return (j);
}
