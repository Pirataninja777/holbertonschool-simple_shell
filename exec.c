#include "shell.h"

void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();  /* Create a child process*/
	if (pid == 0)  /* Child process*/
	{
		if (execve(args[0], args, NULL) == -1)  /* Execute the command*/
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)  /* Fork failed*/
	{
		perror("Fork failed");
	}
	else  /* Parent process*/
	{
		waitpid(pid, &status, 0);  /* Wait for the child to finish*/
	}
}

