#include "function.h"
#include "shell.h"
/**
 * striingified - Converts a given number to a string
 *
 * @numbe: Number to convert will go here
 *
 * Return: Number which is digits will now be string
 * and will be returned as string...
 **/
char *stringified(int numbe)
{
	char *num;
	int max_digit, i;

	max_digit = numberings(numbe);
	num = malloc(max_digit * sizeof(char) + 1);
	if (num == NULL)
		return (NULL);
	if (numbe == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}

	num[max_digit] = '\0';

	for (i = max_digit - 1; numbe != 0; numbe /= 10, i--)
	{
		num[i] = (numbe % 10) + '0';
	}

	return (num);
}
