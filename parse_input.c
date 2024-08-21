#include "shell.h"

/**
 * parse_input - Parses the input line into arguments.
 * @line: The input string to be tokenized.
 * @args: The array to store the parsed tokens.
 *
 * Description: This function splits the input string `line` into
 * tokens using spaces as delimiters. The tokens are stored in the
 * `args` array, which is used to execute commands in a simple shell.
 */
void parse_input(char *line, char **args)
{
	int i = 0;

	args[i] = strtok(line, " ");  /* Split line into tokens by spaces*/
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
}

