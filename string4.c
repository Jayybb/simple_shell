#include "function.h"
#include "shell.h"
/**
 * *_strcpy - pointer to a character
 *
 * @dest: string 1
 * @src: string 2
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
int j;

for (j = 0; src[j] != '\0'; j++)
{
dest[j] = src[j];
}
dest[j] = '\0';

return (dest);
}
