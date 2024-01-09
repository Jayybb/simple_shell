#include "function.h"
#include "shell.h"
/**
 * displayError - This is the function that helps to print to the
 * standard error (2)
 * @message: Message that is to be printed is passed here
 *
 * Return: Number of bytes printed by the function
 **/
int ErrorDisplay(char *message)
{
	return (putToFD(message, 2));
}
