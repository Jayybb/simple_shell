#include "shell.h"
#include "function.h"
/**
 * binaryExit - This function helps exit the shell
 *
 * @str: struct parameter
 * with multipie declaration
 * @args: argument
 *
 * Return: void
 **/
void binaryExit(shell_t *str, char **args)
{

int i, j;

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

freeMemoryPointer((void **) args);
freeMemory((void *) str->buf);
freeMemory((void *) str->env);
freeMemory((void *) str);

exit(j);
}
