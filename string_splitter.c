#include "s_shell.h"

/**
 * mytoken - Tokenizes a string.
 * @userLine: User input.
 * Return: Tokenized string.
 */
char **splitter(char *str)
{
	char **command = NULL, *token = NULL, *temp = NULL;
	int i, t_count = 0;

	if (!str)
		return (NULL);

	temp = _strdup(str);

    token = strtok(temp, " ");
    if (token == NULL)
	{
    	free(temp), temp = NULL;
    	free(str), str = NULL;
        return (NULL);
    }

    while (token)
	{
        t_count++;
        token = strtok(NULL, " ");
    }
    free(temp), temp = NULL;

	command = malloc(sizeof(char *) * (t_count + 1));
	if (!command)
	{
		free(str), str = NULL;
        return (NULL);
	}

	token = strtok(str, " ");
	while (token != NULL)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
    free(str), str = NULL;

	command[i] = NULL;

	return (command);
}
