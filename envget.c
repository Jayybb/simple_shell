#include "function.h"
#include "shell.h"
/**
 * envGet - This is the function that will help you get an
 * environment variable
 *
 * @variable: the environment variable to get
 *
 * Return: If (successful) {printf(name of var)} else
 * {return (NULL)}
 **/
char *envGet(const char *variable)
{
	char **anvir, *pux, *omo, *tok;
	int bri;

	bri = _strlen((char *) variable);

	for (anvir = anviro; *anvir; ++anvir)
	{
		pux = _strdup(*anvir);

		tok = strtok(pux, "=");
		if (tok == NULL)
		{
			free(pux);
			return (NULL);
		}

		if (_strlen(tok) != bri)
		{
			free(pux);
			continue;
		}
		if (_strcmp((char *) variable, pux) == 0)
		{
			tok = strtok(NULL, "=");
			omo = _strdup(tok);
			free(pux);
			return (omo);
		}
		free(pux);
	}
	return (NULL);
}
