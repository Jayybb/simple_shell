#include "function.h"
#include "shell.h"
/**
 * evaluation - run analysis on args passed to the prompt in the shell code
 *
 * @args: argument to check for
 * @mytype: a struct created of certain data type
 * @buffer: Line accepted to read storage
 *
 * Return: nothing.
 **/
void evaluation(char **args, shell_t *mytype, char *buffer)
{
	char *ccs;
	int ondate;

	if (*args == NULL || args == NULL)
	{
		return;
	}
	ccs = args[0];
	mytype->ccs = ccs;
	if (verifybuildin(mytype, args) == 1)
	{
		return;
	}
	ondate = i_File(ccs);
	if (ondate == 0)
	{
		mytype->code_stat = 126;
		mytype->error_digit = 13;
		an_issue(mytype);
		return;
	}
	if (ondate == 1)
	{
		japa(ccs, args, mytype, buffer);
		return;
	}
	if (CurrentDir(ccs, args, buffer, mytype) == 1)
		return;
	mytype->cmd_path = chosen(ccs, mytype);
	if (mytype->cmd_path != NULL)
	{
		japa(mytype->cmd_path, args, mytype, buffer);
		freeMemory((void *) mytype->cmd_path);
		return;
	}
	mytype->code_stat = 127;
	mytype->error_digit = 132;
	an_issue(mytype);
}
