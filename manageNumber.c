#include "function.h"
#include "shell.h"
/**
 * anageNumbering - This function will help
 * Control the argument of exit builtin
 *
 * @mytype: a pointer to the struct to access its types
 * @argument: Argument of the builtin exit passed
 *
 * Return: If the actual argument exist then return 1
 * else return 0 which is negative
 **/
int anageNumbering(shell_t *mytype, char *argument)
{
	int target;

	target = atoi(argument);

	if (target < 0 || i_amLetter(argument))
	{
		mytype->code_stat = 2;
		mytype->error_digit = 133;
		error_addition(mytype, argument);
		return (0);
	}

	if (target > 255)
	{
		mytype->code_stat = target % 256;
	}
	else
	{
		mytype->code_stat = target;
	}

	return (1);
}
