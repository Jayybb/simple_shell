#include "function.h"
#include "shell.h"
/**
 * i_amLetter - search if a digit string contains letter
 *
 * @string: String to check for presence of letter
 *
 * Return: If a non-digits was found, return 1
 * if not, return 0
 **/
int i_amLetter(char *string)
{
	int a;

	for (a = 0; string[a] != '\0'; a++)
	{
		if (i_amNumeric(string[a]) == 0)
			return (1);
	}

	return (0);
}
