#include "s_shell.h"
/**
 * splitter - Tokenizes a string.
 * @str: The string to be tokenized.
 *
 * Return: An array of strings containing the tokens.
 *         Returns NULL if @str is NULL or if memory allocation fails.
 */
char **splitter(char *str)
{
	char **cmd = NULL, *token = NULL, *temp = NULL;
	int t_count = 0;

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
	cmd = malloc(sizeof(char *) * (t_count + 1));
	if (!cmd)
	{
		free(str), str = NULL;
		return (NULL);
	}
	t_count = 0;
	token = strtok(str, " ");
	while (token != NULL)
	{
		cmd[t_count] = _strdup(token);
		token = strtok(NULL, " ");
		t_count++;
	}
	free(str), str = NULL;
	cmd[t_count] = NULL;
	return (cmd);
}
