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

int displayer(char *message)
{
	return (putToFD(message, 1));
}
