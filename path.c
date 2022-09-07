#include "holberton.h"

/**
 * _path - function that prints environment PATH
 * @env: environment
 * @first: the first tokenized keyword (user inputted argument)
 * @input: the tokenized arguments
 * @ex_st: the exit status
 * Return: 0 if successful
 */
int _path(char *first, char **input, char **env, int *ex_st)
{
	int i;
	char *temp, *left, *right;
	char *new = NULL, *envcopy = NULL;

	for (i = 0; env[i] != '\0'; i++)
	{
		envcopy = _strdup(env[i]);
		left = strtok(envcopy, "= \t");
		temp = strtok(NULL, "= \t");

		if (_strcmp(left, "PATH") == 0)
		{
			right = strtok(temp, ": \t");
			while (right)
			{
				new = pathstr(right, first);

				if (access(new, X_OK) == 0)
				{
					if (fork() == 0)
						execve(new, input, NULL);

					else
						wait(NULL);
					*ex_st = 0;
					free(new);
					free(envcopy);
					return (0);
				}
				right = strtok(NULL, ": \t");
				free(new);
			}
		}
		free(envcopy);
	}
	return (2);
}
