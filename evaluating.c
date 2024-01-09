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
		run(ccs, args, mytype, buffer);
		return;
	}
	if (getCurrentDir(ccs, args, buffer, mytype) == 1)
		return;
	mytype->cur_path = close(ccs, mytype);
	if (mytype->cur_path != NULL)
	{
		run(mytype->cur_path, args, mytype, buffer);
		freeMemory((void *) mytype->cur_path);
		return;
	}
	mytype->code_stat = 127;
	mytype->error_digit = 132;
	an_issue(mytype);
}
