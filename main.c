#include "s_shell.h"

/**
 * main - Entry point of the shell program.
 *
 * @ac: The number of arguments passed to the program.
 * @av: An array of strings containing the arguments passed to the program.
 *
 * Return: The exit status of the shell program.
 */
int main(int ac, char **av)
{
	char **cmd = NULL, *line = NULL;
	int status = 0;
	(void) ac;
	(void) av;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		cmd = splitter(line);
		if (!cmd)
			continue;

		status = _execute(cmd, av);
	}
}
