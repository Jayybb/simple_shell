#include "shell.h"
#include "function.h"
/**
 * binEnv - fix functions into the shell
 * @str: struct
 * @args: argument
 *
 * Return
 **/
void binEnv(shell_t *str, char **args)
{
(void) str;
(void) args;

fetchFullEnv();
}
