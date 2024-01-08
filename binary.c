#include "shell.h"
#include "function.h"
/**
 * binExit - This function helps exit the shell
 *
 * @str: struct parameter
 * with multipie declaration
 * @args: argument
 *
 * Return: void
 **/
void binExit(shell_t *str, char **args)
{

int i, int j;

i = 1;
if (args[1] != NULL)
{
i = manageNumbers(str, args[1]);
}

if (i == 0)
{
return;
}

j = str->code_stat;

releaseMemoryPointer((void **) args);
releaseMemory((void *) str->buf);
releaseMemory((void *) str->env);
releaseMemory((void *) str);

exit(j);
}
