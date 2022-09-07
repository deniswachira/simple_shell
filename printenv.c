#include "holberton.h"

/**
 * printenv - prints the environment variable
 * @env: the environment variable to print
 * @ex_st: exit status
 * Return: Always (0) for sucess
 */
int printenv(char **env, int *ex_st)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		print_str(env[i]);
		_putchar('\n');
		i++;
	}
	*ex_st = 0;
	return (EXIT_SUCCESS);
}
