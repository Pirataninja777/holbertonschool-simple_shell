#include "shell.h"
/**
 * execute_command - Executes a command in a child process.
 * @args: The array of arguments for the command to execute.
 *
 * Description: This function forks the current process to create a child
 * process. The child process attempts to execute the command specified
 * in `args[0]` using `execve`. If the execution fails, an error message
 * is printed. The parent process waits for the child process to complete.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();  /* Create a child process*/
	if (pid == 0)  /* Child process*/
	{
		if (execve(args[0], args, environ) == -1)  /* Execute the command*/
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

