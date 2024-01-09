#include "function.h"
#include "shell.h"
/**
 * fetchFullEnv - This function will help get all
 * the environment variable
 *
 * Return: nothing, just get the env. variable and carry on
 *
 **/
void fetchFullEnv(void)
{
	int a = 0;
	char **temp;

	for (a = 0, temp = environ; temp[a] != NULL; a++)
	{
		displayer(temp[a]);
		writeCharacter('\n');
	}
}
