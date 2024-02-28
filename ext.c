#include "s_shell.h"

/**
 * _execute - Executes a command with arguments.
 * @cmd: An array of strings representing the command and its arguments.
 * @av: An array of strings containing the program name and its arguments.
 * @idx: The index of the command in the input.
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **cmd, char **av, int idx)
{
	int status;
	pid_t child_pid;
	char *full_cmd;

	full_cmd = get_path(cmd[0]);
	if (!full_cmd)
	{
		print_err(av[0], cmd[0], idx);
		free_2Darr(cmd);
		return (127);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(full_cmd, cmd, environ))
		{
			free(full_cmd), full_cmd = NULL;
			free_2Darr(cmd);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free_2Darr(cmd);
		free(full_cmd), full_cmd = NULL;
	}

	return (WEXITSTATUS(status));
}
