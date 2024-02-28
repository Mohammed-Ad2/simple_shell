#include "s_shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @vaiable: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable.
 *         Returns NULL if the variable is not found.
 */
char *_getenv(char *vaiable)
{
	char *temp_str, *key, *value, *env_value;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp_str = strdup(environ[i]);
		key = strtok(temp_str, "=");
		if (strcmp(key, vaiable) == 0)
		{
			value = strtok(NULL, "\n");
			env_value = strdup(value);
			free(temp_str);
			return (env_value);
		}
		free(temp_str), temp_str = NULL;
	}
	return (NULL);
}
