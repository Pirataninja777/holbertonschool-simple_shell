#include "shell.h"

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

