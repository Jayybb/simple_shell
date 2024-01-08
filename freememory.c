#include "function.h"
#include "shell.h"
/**
 * freeMemory - This function helps to free a pointer
 *
 * @ptr: Pointer to free is passed
 * Return: void
 **/
void freeMemory(void *ptr)
{
if (ptr != NULL)
{
free(ptr);
ptr = NULL;
}
ptr = NULL;
}
