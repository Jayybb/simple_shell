#include "function.h"
#include "shell.h"
/**
 * lookFullEnv - This function will help get all
 * the environment variable
 *
 * Return: nothing, just get the env. variable and carry on
 *
 **/
void lookFullEnv(void)
{
	int a = 0;
	char **temp;

	for (a = 0, temp = environ; temp[a] != NULL; a++)
	{
		displayer(temp[a]);
<<<<<<< HEAD
		writeCharacter('\n', 1);
=======
		characterWriter('\n');
>>>>>>> 8ea1ba3457e115a2034552b91fe6366f74b7075f
	}
}
