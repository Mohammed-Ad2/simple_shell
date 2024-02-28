#include "s_shell.h"

/**
 * _execute - Executes a command with arguments.
 * @cmd: An array of strings representing the command and its arguments.
 * @av: An array of strings containing the program name and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **cmd, char **av)
{
	int status;
	pid_t child_value;

	child_value = fork();
	if (child_value == 0)
	{
		if (execve(cmd[0], cmd, environ))
		{
			perror(av[0]);
			free_2Darr(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_2Darr(cmd);
	}

	return (WEXITSTATUS(status));
}
