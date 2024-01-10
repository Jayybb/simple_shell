#include "function.h"
#include "shell.h"
/**
 * wordsMerg - Join 3 words with a delimitar / spearator
 *
 * @j1: Word1 to merge
 * @j2: Word2 to merge
 * @j3: Word3 to merge 
 * @delx: Separator command 
 *
 * Return: a string composed of strings joined together
 **/
char *wordsMerg(char *j1, char *j2, char *j3, const char *delx)
{
	int size1, size2, size3, del_size;
	char *joint;

	size1 = size2 = size3 = del_size = 0;

	if (j2 != NULL)
		size2 = _strlen(j2);
	else
		j2 = "";

	if (j1 != NULL)
		size1 = _strlen(j1);
	else
		j1 = "";
	if (j3 != NULL)
		size3 = _strlen(j3);
	else
		j3 = "";
	if (delx != NULL)
		del_size = _strlen((char *)delx);
	else
		delx = "";

	joint = malloc(size1 + del_size + size2 + del_size + size3 + 2);
	if (joint == NULL)
	{
		return (NULL);
	}
	joint = _strcpy(joint, j1);
	joint = _strcat(joint, (char *)delx);
	joint = _strcat(joint, j2);
	joint = _strcat(joint, (char *)delx);
	joint = _strcat(joint, j3);
	joint = _strcat(joint, "\n");

	return (joint);
}
