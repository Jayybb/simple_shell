#include "function.h"
#include "shell.h"
/**
 * additionalError - This is the function that Prints the error
 * message with extra and more information about error
 *
 * @mytype: a struct that gives info about shell
 * also decleares a type for this info
 * @more: The Extra information about the error messages
 *
 * Return: nothing.... print error and comtinue.
 **/
void additionalError(shell_t *mytype, char *more)
{
	char *num, *mrg;
	char *bp, *bp2;
	int num_size, mrg_size;
	int more_size;

	num = NULL;
	mrg = selectMessage(*mytype);
	num = stringify(mytype->n_cmd);

	num_size = _strlen(num);
	mrg_size = _strlen(mytype->argv[0]);
	more_size = _strlen(more);

	bp = malloc(mrg_size + num_size + 3);
	bp = _strcpy(bp, mytype->argv[0]);
	bp = _strcat(bp, ": ");
	bp = _strcat(bp, num);

	bp2 = malloc(_strlen(mrg) + more_size + 3);
	bp2 = _strcpy(bp2, mrg);
	bp2 = _strcat(bp2, ": ");
	bp2 = _strcat(bp2, more);

	mrg = mergeWords(bp, mytype->cmd, bp2, ": ");
	ErrorDisplay(mrg);

	free(mrg);
	free(num);
	free(bp);
	free(bp2);
}
