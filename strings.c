#include "s_shell.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory.
 * @str: Input string.
 * Return: Pointer to an array of characters.
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i;
	int len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		ptr[i] = str[i];

	ptr[i] = '\0';
	return (ptr);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the resulting string (dest).
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len = 0;

	while (dest[i])
	{
		dest_len++;
		i++;
	}

	for (i = 0; src[i]; i++)
		dest[dest_len++] = src[i];

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: First input string.
 * @s2: Second input string.
 * Return: 0 if equal, positive or negative value if different.
 */
int _strcmp(const char *s1, const char *s2)
{
	int i, result = 0;

	for (i = 0; s1[i] != '\0' && result == 0; i++)
		result = s1[i] - s2[i];

	return (result);
}

/**
 * _strlen - Returns the length of a string.
 * @s: Input string.
 * Return: Length of the string.
 */
size_t _strlen(const char *s)
{
	int length = 0;

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * _strcpy - Copies the string pointed to by src.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the resulting string (dest).
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
