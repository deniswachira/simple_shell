#include "holberton.h"

/**
 * main - Program that is simple UNIX command interpreter
 * @argc: argument count
 * @argv: argument vector
 * @env: the environment
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *prompt = "##--->";
	char *line = NULL;
	char **args = NULL;
	int i = 0, status = 0, arg_num = 0;
	static int exit_stat, tally;
	size_t len = 0;
	ssize_t read = 0;
	(void)argc, (void)**argv;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, 6);

		read = getline(&line, &len, stdin);
		++tally;
		if (special_char(line, read, &exit_stat) == 127)
			continue;

		no_nl(line);

		args = parser(line);

		for (i = 0; args[i]; i++)
			arg_num++;

		builtins(line, args, env, &exit_stat);

		status = _path(args[0], args, env, &exit_stat);

		_execute(status, args, &exit_stat, &tally);

		fflush(stdin);
	}
	free(line);
	return (0);
}
