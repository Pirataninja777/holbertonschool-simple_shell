#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void parse_input(char *line, char **args);
void execute_command(char **args);

#endif /* SHELL_H */

