#include "function.h"
#include "shell.h"
/**
 * writeCharacterTioFD - This function will help write
 * charcaters to a specific file descriptor
 *
 * @cha: Character to print
 * @fil_d: specifiy file descriptor to be 0 1 or 2
 *
 * Return: On success 1.
 **/
int writeCharacterToFD(char cha, int fil_d)
{
	return (write(fil_d, &cha, 1));
}
