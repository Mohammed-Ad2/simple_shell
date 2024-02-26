#include "s_shell"

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
