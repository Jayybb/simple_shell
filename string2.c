#include "shell.h"
#include "function.h"
/**
 * _strlen - function that returns the string length
 *
 * @s: strings
 *
 * Return: (0)
 */
int _strlen(char *s)
{
int i;

i = 0;
while (s[i] != '\0')
{
i++;
}

return (i);
}
