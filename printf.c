#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1. On error, -1 is returned..
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_str - prints string
 * @s: string to be printed
 * Return: void
 */
void print_str(char *s)
{
	int i, bytes, wc;

	for (i = 0; s[i] != '\0'; i++)
		;

	bytes = i;

	wc = write(STDOUT_FILENO, s, bytes);
	if (wc == EOF)
		return;
}


/**
 * pathstr - function that prints the path string
 * @right: string after "PATH ="
 * @first: first tokenized word
 * Return: 0 for success
 */
char *pathstr(char *right, char *first)
{
	char *new = NULL;
	char *token = NULL;
	int token_len = 0, first_len = 0;

	token = right;
	token_len = _strlen(token);
	first_len = _strlen(first);

	new = malloc((token_len + first_len + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);

	new[0] = '\0';

	_strcat(new, right);
	_strcat(new, "/");
	_strcat(new, first);
	_strcat(new, "\0");

	return (new);
}

/**
 * print_int - prints an integer
 * @tally: pointer to the tally number
 * Return: void
 */
void print_int(int *tally)
{
	int count = 0, length = 0, j, n;
	unsigned int base = 1, d, max;

	n = *tally;

	max = n;
	d = max;

	do {
		d /= 10;
		++length;
	} while (d != 0);

	count += length;

	for (j = 0; j < length -  1; j++)
		base = base * 10;

	_putchar('0' + (max / base));

	if (length > 1)
	{
		for (j = 0; j < length - 2; j++)
		{
			base /= 10;
			d = max / base;
			_putchar('0' + d % 10);
		}
		_putchar('0' + (max % 10));
	}
}


/**
 * parser - function that takes a string from the command line and returns the
 * string as a parsed double pointer using a space as the delimiter
 * @l: Char pointer storing user input
 * Return: Char double pointer comprised of a char pointers that each contain
 * an argument
 */

char **parser(char *l)
{
	char **args;

	char *parsed = NULL;
	char *parsed2 = NULL;
	char *linecopy = NULL;

	int arg_num = 0, i = 0;

	linecopy = _strdup(l);
	parsed = strtok(linecopy, " \t");

	while (parsed != NULL)
	{
		arg_num++;
		parsed = strtok(NULL, " \t");
	}

	args = malloc(sizeof(char *) * (arg_num + 1));

	if (args == NULL)
		return (NULL);

	parsed2 = strtok(l, " \t");

	while (parsed2 != NULL)
	{
		args[i] = parsed2;
		parsed2 = strtok(NULL, " \t");
		i++;
	}

	args[i] = NULL;
	free(linecopy);
	return (args);
}
