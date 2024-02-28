#include "s_shell.h"

/**
 * is_builtin - Checks if a command is a built-in command.
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in command, 0 otherwise.
 */
int is_builtin(char *cmd)
{
	char *builtins[] = {
		"exit",
		"env",
		"setenv",
		"cd",
		NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
		if (_strcmp(cmd, builtins[i]) == 0)
			return (1);

	return (0);
}

/**
 * h_builtin - Executes built-in commands.
 *
 * @cmd: An array of strings representing the command
 *	 and its arguments.
 * @av: An array of strings containing the program name
 *	and its arguments.
 * @status: Pointer to the status variable.
 * @index: The index of the command in the input.
 */
void h_builtin(char **cmd, char **av, int *status, int index)
{
	(void) av;
	(void) index;

	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, av, status, index);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, status);
}

/**
 * exit_shell - Handles the 'exit' built-in command.
 *
 * @cmd: An array of strings representing the command
 *	 and its arguments.
 * @av: An array of strings containing the program name
 *	and its arguments.
 * @status: Pointer to the status variable.
 * @idx: The index of the command in the input.
 */
void exit_shell(char **cmd, char **av, int *status, int idx)
{
	char *index, msg[] = ": exit: Illegal number: ";
	int exit_v = (*status);

	if (cmd[1])
	{
		if (is_p_n(cmd[1]))
			exit_v = _atoi(cmd[1]);
	else
	{
		index = _itoa(idx);
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, index, _strlen(index));
		write(STDERR_FILENO, msg, _strlen(msg));
		write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
		write(STDERR_FILENO, "\n", 1);
		free(index);
		free_2Darr(cmd);
		*status = 2;
			return;
		}
	}

	free_2Darr(cmd);
	exit(exit_v);
}

/**
 * print_env - Handles the 'env' built-in command.
 *
 * @cmd: An array of strings representing the command
 *	 and its arguments.
 * @status: Pointer to the status variable.
 */
void print_env(char **cmd, int *status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	free_2Darr(cmd);
	(*status) = 0;
}
