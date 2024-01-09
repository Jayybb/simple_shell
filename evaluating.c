#include "function.h"
#include "shell.h"
/**
 * evaluate - run analysis on args passed to the prompt in the shell code
 *
 * @args: argument to check for
 * @mytype: a struct created of certain data type
 * @buffer: Line accepted to read storage
 *
 * Return: nothing.
 **/
void evaluate(char **args, shell_t *mytype, char *buffer)
{
	char *ccs;
	int new;

	if (*args == NULL || args == NULL)
	{
		return;
	}
	ccs = args[0];
	mytype->ccs = ccs;
	if (verifyBuiltin(mytype, args) == 1)
	{
		return;
	}
	new = isFile(ccs);
	if (update == 0)
	{
		mytype->code_stat = 126;
		mytype->error_digit = 13;
		issue(mytype);
		return;
	}
	if (new == 1)
	{
		run(ccs, args, mytype, buffer);
		return;
	}
	if (getCurrentDir(ccs, args, buffer, mytype) == 1)
		return;
	mytype->ccs_path = choose(ccs, mytype);
	if (mytype->ccs_path != NULL)
	{
		run(mytype->ccs_path, args, mytype, buffer);
		releaseMemory((void *) mytype->ccs_path);
		return;
	}
	mytype->code_stat = 127;
	mytype->error_digit = 132;
	issue(mytype);
}
