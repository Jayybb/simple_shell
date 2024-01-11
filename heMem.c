#include "shell.h"

/**
 *bFree - Thiis will frees a pointer and sets it to NULL.
 *@ptr: A pointer that needs to be freed.
 *
 *This function frees the memory pointedthe pointer to NULL to 
 *avoid any dangling references.
 *
 *Return: 1 if the memory was successfully freed, 0 otherwise.
 */
int bFree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}
