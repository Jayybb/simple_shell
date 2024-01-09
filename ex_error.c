#include "function.h"
#include "shell.h"
/**
 * additionalError - This is a function that Prints the error
 * message with extra/more information about the error
 *
 * @mytype: a struct that gives info about the shell
 * also decleares a type for this information
 * @more: The Extra information or more info about the error
 * message
 *
 * Return: nothing.... just print error.
 **/
void additionalError(shell_t *mytype, char *more)
{
	char *mag, *nub;
	char *au, *au2;
	int nub_size, mag_size;
	int more_size;

	nub = NULL;
	mag = selectMessage(*mytype);
	nub = stringify(mytype->n_cmd);

	nub_size = _strlen(nub);
	mag_size = _strlen(mytype->argv[0]);
	more_size = _strlen(more);

	au = malloc(mag_size + nub_size + 3);
	au = _strcpy(au, mytype->argv[0]);
	au = _strcat(au, ": ");
	au = _strcat(au, nub);

	au2 = malloc(_strlen(mag) + more_size + 3);
	au2 = _strcpy(au2, mag);
	au2 = _strcat(au2, ": ");
	au2 = _strcat(au2, more);

	mag = mergeWords(au, mytype->cmd, au2, ": ");
	ErrorDisplay(mag);

	free(mag);
	free(nub);
	free(au);
	free(au2);
}
