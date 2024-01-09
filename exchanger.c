#include "function.h"
#include "shell.h"
/**
 * exchange - This function is used to replace in the shell
 *
 * @mytype: a struct call that takes in a pointer
 * @id: index parameter to take note
 * @word: the inputed words
 *
 * Return: pointer to the string
**/
char *exchange(shelldata_t *mytype, int *id, char *word)
{
	char *tem, told;

	(void) id;

	told = *word;
	if (told != '?' && told != '$')
	{
		tem = subEnv(mytype, word);
		return (tem);
	}

	tem = (told == '$') ? stringify(mytype->pid) :
		stringify(mytype->code_stat);

	return (tem);
}
