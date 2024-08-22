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
	char *args[MAX_ARGS];
	size_t lineSize = 0;
	ssize_t bytesRead;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("%s/%s$ ", getenv("USER"), getenv("PWD"));
			fflush(stdout);
		}
		bytesRead = getline(&line, &lineSize, stdin);
		if (bytesRead == EOF)
		{
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			free(line);
			perror("Error");
			continue;

		}
		line[bytesRead - 1] = '\0';
		tokenize(line, args, MAX_ARGS);
		tokenize(line, args, MAX_ARGS);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			exec(args);
		}
		memset(args, 0, sizeof(args));
	}
	free(line);
	return (0);
}
