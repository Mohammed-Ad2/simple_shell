#include "s_shell.h"

/**
 * main - entry point
 *
 * return: 
*/
int main(int ac, char **av)
{
		char **command = NULL;
			char *line = NULL;
				int i, status = 0;
					(void) ac;
						(void) av;

							while (1)
									{
												line = read_line();
														if (line == NULL)
																	{
																					if (isatty(STDIN_FILENO))
																										write(STDOUT_FILENO, "\n", 1);
																								return (status);
																										}

																command = splitter(line);
																		if (!command)
																						continue;

																				/* status = executer(command, av); */
																			}
}
