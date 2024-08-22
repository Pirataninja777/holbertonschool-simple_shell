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

int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char *args[1024];

	while (1)
	{
		printf("#cisfun$ ");  /* Display prompt*/
		read = getline(&line, &len, stdin);  /* Get user input*/

		if (read == -1)  /* Handle EOF (Ctrl+D)*/
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

		line[read - 1] = '\0';  /* Remove newline character*/
		parse_input(line, args);  /* Parse the input into arguments*/

		if (args[0] != NULL)
		{
			/*if (strcmp(args[0], "exit") == 0)
				break;*/

			execute_command(args);  /* Execute the command*/
		}
	}

	free(line);
	return (0);
}

