#include "function.h"
#include "shell.h"
/**
 * mergeWords - Join 3 words with a delimitar / spearator
 *
 * @j1: Word1 to merge
 * @j2: Word2 to merge
 * @j3: Word3 to merge 
 * @delete: Separator command 
 *
 * Return: a string composed of strings joined together
 **/
char *mergeWords(char *j1, char *j2, char *j3, const char *delete)
{
	int size1, size2, size3, del_size;
	char *joint;

	size1 = size2 = size3 = del_size = 0;

	if (w2 != NULL)
		size2 = _strlen(w2);
	else
		w2 = "";

	if (w1 != NULL)
		size1 = _strlen(w1);
	else
		w1 = "";
	if (w3 != NULL)
		size3 = _strlen(w3);
	else
		w3 = "";
	if (del != NULL)
		del_size = _strlen((char *)del);
	else
		del = "";

	joint = malloc(size1 + del_size + size2 + del_size + size3 + 2);
	if (joint == NULL)
	{
		return (NULL);
	}
	joint = _strcpy(joint, w1);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w2);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w3);
	joint = _strcat(joint, "\n");

	return (joint);
}
