#include "shell.h"

/**
 * get_env - Gets the environments variables value.
 *
 * @var: the environment variable that we are getting.
 * Return: String containing the value of the var.
 * Return: NULL if variable isnt found or
 * in case memory fails
 */

char *get_env(char *var)
{
	char *tmp, *value, *key, *env;
	int i;

	for (i = 0, environ[i]; i++)
	{
		key = strtok(tmp, "=");

		if (key !== NULL && strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}


