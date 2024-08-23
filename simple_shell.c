#include "shell.h"

/**
 * main - Entry point of the simple shell program.
 *
 * Description: This program implements a simple shell that repeatedly
 * prompts the user for input, parses the input into arguments, and
 * executes the corresponding command. The shell continues to run until
 * the user inputs the "exit" command or sends an EOF (Ctrl+D).
 *
 * Return: Always returns 0.
 */

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *args[1024];
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}
			
		read = getline(&line, &len, stdin);
		

		if (read == -1)
		{
			printf("\n");
			break;
		}

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (read);
		}

		line[read - 1] = '\0';
		parse_input(line, args);

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
				break;

			execute_command(args);
		}
	}

	free(line);
	return (0);
}
