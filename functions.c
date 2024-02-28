#include "s_shell.h"

/**
 * free_2Darr - Frees memory allocated for a two-dimensional
 *              array of strings.
 *
 * @arr: The two-dimensional array of strings to be freed.
 */
void free_2Darr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
}

/**
 * print_err - Prints an error message to stderr.
 *
 * @name: The name of the program.
 * @cmd: The command that caused the error.
 * @idx: The index of the command in the input.
 */
void print_err(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	swap_str(buffer, i);
	return (_strdup(buffer));
}

/**
 * swap_str - Reverses a string.
 *
 * @str: The string to reverse.
 * @len: The length of the string.
 */
void swap_str(char *str, int len)
{
	char temp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
