#include "function.h"
#include "shell.h"
/**
 * exchanging - This function is used to replace in the shell
 *
 * @mytype: a struct call that takes in a pointer
 * @id: index parameter to take note
 * @word: the inputed words
 *
 * Return: pointer to the string
**/
char *exchanging(shell_t *mytype, int *id, char *word)
{
	char *tem, told;

	(void) id;

	told = *word;
	if (told != '?' && told != '$')
	{
		tem = sunAnv(mytype, word);
		return (tem);
	}

	tem = (told == '$') ? stringified(mytype->pid):
		stringified(mytype->code_stat);

	return (tem);
}
