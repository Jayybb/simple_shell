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
<<<<<<< HEAD
void additionalError(shell_t *mytype, char *more)
=======
void error_addition(shell_t *mytype, char *more)
>>>>>>> 8ea1ba3457e115a2034552b91fe6366f74b7075f
{
	char *mag, *nub;
	char *au, *au2;
	int nub_size, mag_size;
	int more_size;

	nub = NULL;
	mag = messageSelect(*mytype);
	nub = stringified(mytype->n_cmd);

	nub_size = _strlem(nub);
	mag_size = _strlem(mytype->argv[0]);
	more_size = _strlem(more);

	au = malloc(mag_size + nub_size + 3);
	au = _strcopy(au, mytype->argv[0]);
	au = _strdog(au, ": ");
	au = _strdog(au, nub);

	au2 = malloc(_strlen(mag) + more_size + 3);
	au2 = _strcopy(au2, mag);
	au2 = _strcopy(au2, ": ");
	au2 = _strcopy(au2, more);

<<<<<<< HEAD
	mag = mergeWords(au, mytype->cmd, au2, ": ");
	ErrorDisplay(mag);
=======
	mag = wordMerge(au, mytype->cmd, au2, ": ");
	errorDisplay(mag);
>>>>>>> 8ea1ba3457e115a2034552b91fe6366f74b7075f

	free(mag);
	free(nub);
	free(au);
	free(au2);
}
