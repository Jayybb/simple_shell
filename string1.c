#include "shell.h"
#include "function.h"
/**
 * _strcat - concertenate two strings in a buffer
 *
 * @dest: the destination string
 * @src: the source string
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
int i, j, k;

for (i = 0; dest[i] != '\0'; i++)
{

}

for (j = 0; src[j] != '\0'; j++)
{

}
for (k = 0; k <= j; k++)
{
dest[i + k] = src[k];
}

return dest;
}
