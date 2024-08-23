# Simple Shell Project

## Description

This project implements a basic shell in C. The shell allows reading and executing user commands, displaying environment variables, and handling basic errors. The project includes functions for tokenizing strings, managing environment variables, executing commands, and handling linked lists.

|## Functions|-----|
|-----|------------|
|### `main`|The main function that runs the shell. It reads commands, handles environment variables, tokenizes commands, and executes them.|
|### `Read_line`|
Prints a prompt and reads a line of input from the user. Handles the `exit` command and input closure.|
|### `tokenicer`|
Tokenizes an input string using a delimiter and stores the tokens in a linked list.|
|### `add_node_end`|
Adds a node to the end of a linked list.|
|### `free_list`|
Frees the memory of a linked list.|
|### `_getenv`|
Searches and extracts the value of an environment variable.|
|### `_stat_checker`|
Checks the status of files using a list of tokens and a list of paths. Returns the full path of the file if found.|
|### `_list_to_array`|
Converts a linked list into an array of strings.|
|### `_EXE_Cute`|
Executes a command on the system.|
|### `_env`|
Prints all environment variables.|
|### `_concat`|
Concatenates two strings.|


## Installation

To compile the project, ensure you have a C compiler compatible with the GNU89 standard. Clone the repository and compile the code using `gcc`.

```bash
git clone git@github.com:Pirataninja777/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell


