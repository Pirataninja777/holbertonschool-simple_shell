#include "shell.h"

/**
 * main - entry point of the simple shell program
 *
 * Description: This program implements a simple shell that repeatedly
 * prompts the user for input, parses the input into arguments, and
 * executes the corresponding command. The shell continues to run until
 * the user inputs the "exit" command or sends an EOF (Ctrl+D).
 *
 * Return: Always returns 0 on success.
 */
int main(void)
{
	char *line = NULL;
	char **args;
	size_t line_size = 0;
	ssize_t bytes_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("%s$ ", getenv("USER"));
			fflush(stdout);
		}

		bytes_read = getline(&line, &line_size, stdin);
		if (bytes_read == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		line[bytes_read - 1] = '\0';

		args = malloc(MAX_ARGS * sizeof(char *));
		if (args == NULL)
		{
			perror("malloc failed");
			free(line);
			exit(EXIT_FAILURE);
		}

		tokenize(line, args, MAX_ARGS);

		if (args[0] != NULL)
		{
			/*if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(line);
				exit(EXIT_SUCCESS);
			}*/
			exec(args);
		}

		free(args);
	}

	free(line);
	return (0);
}

