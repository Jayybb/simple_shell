#include "shell.h"
#include "function.h"

/**
 * buildins - This function execute buildins
 * @str: a struct continung shell info
 * @args: shell command
 *
 * Return: 1 if buildin is present, 0 if not
 **/
int buildins(shell_t *str, char **args)

{
int i;
i = verifybuildin(str, args);
if (i == 0)
{
return (0);
}
return (1);
}
