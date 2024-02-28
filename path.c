#include "s_shell.h"
/**
 * get_path - Searches for the full path of a command.
 * @cmd: The command to search for.
 * Return: A pointer to a string containing the full path of the command.
 *         Returns NULL if the command is not found in the PATH
 *         environment variable.
 */
char *get_path(char *cmd)
{
	int i;
	char *path_env, *full_cmd, *dir;
	struct stat file_stats;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &file_stats) == 0)
			return (_strdup(cmd));
			return  (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (!full_cmd)
		{
			perror("malloc:");
			exit(EXIT_FAILURE);
		}
		_strcpy(full_cmd, dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, cmd);
		if (stat(full_cmd, &file_stats) == 0)
		{
			free(path_env);
			return (full_cmd);
		}
		free(full_cmd), full_cmd = NULL;
		dir = strtok(NULL, ":");
	}
	free(path_env);
	return (NULL);
}
