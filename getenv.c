#include "shell.h"

/**
 * getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *getenv(const char *name)
{
    extern char **environ;
    char **env = environ;
    size_t name_len = strlen(name);

    while (*env != NULL)
    {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            return (*env + name_len + 1);
        }
        env++;
    }

    return (NULL);
}

