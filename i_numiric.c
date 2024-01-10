#include "function.h"
#include "shell.h"
/**
 * i_amNumeric - Check if a given parameter is a digit
 *
 * @number: Number needed to check
 *
 * Return: 1 if it is a number and return 0 if not
 *
 */
int i_amNumeric(unsigned int number)
{
	return (number >= '0' && number <= '9');
}
