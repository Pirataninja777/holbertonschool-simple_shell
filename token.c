#include "main.h"

/**
 * tokenize - Tokenizes a string into an array of strings.
 * @line: The string to tokenize.
 * @args: Array of strings to store the tokens.
 * @max_args: Maximum number of tokens to store.
 *
 * Return: void
 */
void tokenize(char *line, char *args[], size_t max_args)
{
	char *token;
	unsigned int i = 0;

	token = strtok(line, " ");
	while (token != NULL && i < max_args - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}

