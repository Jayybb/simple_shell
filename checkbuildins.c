#include "shell.h"
#include "function.h"

/**
 * verifybuildin - confirms a buildin
 * @str: struct with a data type
 * @args: arguments
 *
 * Return: 1 for buildin and 0 if not
 **/
int verifybuildin(shell_t *str, char **args)

{
int i, j;
sysfunction_t buildin[] = {
{"exit, binEXIT}
{"env, binENV}
};

j = sizeof(buildin) / sizeof(buildin[0]);
i = 0
while (i < j)
{
if (strcmp(str->cmd, buildin[i].cmd) == 0)
{
buildins[i].func(str, args);
return (1);
}
i++;
}
return (0);
}
