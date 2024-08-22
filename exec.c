#include "shell.h"

/**
 * exec - executes the input received
 * @args: arguments to execute
 * Return: void
 */

void exec(char **args)
{
	char *command_path;
	pid_t childPid;
	int status;
	int statusExit;

	if (args == NULL || args[0] == NULL)
	{
		fprintf(stderr, "No command provided\n");
		return;
	}

	command_path = find_path(args[0]);

	if (command_path == NULL && access(args[0], X_OK) != 0)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}

	childPid = fork();
	if (childPid == -1)
	{
		perror("fork");
		free(command_path);
		return;
	}

	if (childPid == 0)
	{
		if (execve(command_path ? command_path : args[0], args, environ) == -1)
		{
			perror("execve");
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(childPid, &status, 0) == -1)
		{
			perror("waitpid");
		}

		if (WIFEXITED(status))
		{
			statusExit = WEXITSTATUS(status);
		}
	}

	free(command_path);
}
