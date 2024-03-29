#include "s_shell.h"

/**
 * read_line - Reads a line of input from the standard input.
 *
 * Return: A pointer to the buffer containing he line read,
 *         NULL If an error occurs or end-of-file is reached.
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t size_buffer = 0;
	ssize_t n_char;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n_char = getline(&buffer, &size_buffer, stdin);
	if (n_char == -1)
	{
		free(buffer);
		return (NULL);
	}

	if (buffer[n_char - 1] == '\n')
		buffer[n_char - 1] = '\0';

	return (buffer);
}
