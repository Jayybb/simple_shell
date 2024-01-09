#include "function.h"
#include "shell.h"
/**
 * outputToFD - Used to print strings to file descriptor
 *
 * @message: instead of character a string is printed out
 * @fil_d: File descriptor to print to either 1 2 or 0
 *
 * Return: On success numbers of bytes printed is returned
 **/
int outputToFD(char *message, int fil_d)
{
	int buff;

	buff = _strlen(message);
	return (write(fil_d, message, buff));
}
