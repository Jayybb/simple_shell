#include "function.h"
#include "shell.h"
/**
 * error_addition - This is the function that Prints the error
 * message with extra and more information about error
 *
 * @mytype: a struct that gives info about shell
 * also decleares a type for this info
 * @more: The Extra information about the error messages
 *
 * Return: nothing.... print error and comtinue.
 **/
void error_addition(shell_t *mytype, char *more)
{
	char *num, *mrg;
	char *bp, *bp2;
	int num_size, mrg_size;
	int more_size;

	num = NULL;
	mrg = messageSelect(*mytype);
	num = stringified(mytype->n_cmd);

	num_size = _strlem(num);
	mrg_size = _strlem(mytype->argv[0]);
	more_size = _strlem(more);

	bp = malloc(mrg_size + num_size + 3);
	bp = _strcopy(bp, mytype->argv[0]);
	bp = _strdog(bp, ": ");
	bp = _strdog(bp, num);

	bp2 = malloc(_strlen(mrg) + more_size + 3);
	bp2 = _strcopy(bp2, mrg);
	bp2 = _strdog(bp2, ": ");
	bp2 = _strdog(bp2, more);

	mrg = wordMerge(bp, mytype->cmd, bp2, ": ");
	errorDisplay(mrg);

	free(mrg);
	free(num);
	free(bp);
	free(bp2);
}
