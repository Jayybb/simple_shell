#include "function.h"
#include "shell.h"
/**
 * freeMemoryPointer - This function helps to free a double pointer
 *
 * @ptr: the pointer to a pointer to free
 * Return: void
 **/
void freeMemoryPointer(void **ptr)
{
void **temp;

for (temp = ptr; *temp != NULL; temp++)
{
freeMemory(*temp);
}

freeMemory(ptr);
}
