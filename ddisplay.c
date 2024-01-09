#include "function.h"
#include "shell.h"

/**
 * display - This prints the message to the standard"
 *
 * @message : Message to the stdout
 *
 * Return: No of byte that arer printed
 *
 * **/

int display(char *message)
{
	return (outputToFD(message, 1));
}
