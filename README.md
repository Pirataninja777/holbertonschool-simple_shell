# Simple Shell Project

## Description

This project implements a basic shell in C. The shell allows reading and executing user commands, displaying environment variables, and handling basic errors. The project includes functions for tokenizing strings, managing environment variables, executing commands, and handling linked lists.


|**Functions**|**Description**|
|-----|------------|
|`main`|The main function that runs the shell. It reads commands, handles environment variables, tokenizes commands, and executes them.|
|`Read_line`|Prints a prompt and reads a line of input from the user. Handles the `exit` command and input closure.|
|`tokenicer`|Tokenizes an input string using a delimiter and stores the tokens in a linked list.|
|`add_node_end`|Adds a node to the end of a linked list.|
|`free_list`|Frees the memory of a linked list.|
|`_getenv`|Searches and extracts the value of an environment variable.|
|`_stat_checker`|Checks the status of files using a list of tokens and a list of paths. Returns the full path of the file if found.|
|`_list_to_array`|Converts a linked list into an array of strings.|
|`_EXE_Cute`|Executes a command on the system.|
|`_env`|Prints all environment variables.|
|`_concat`|Concatenates two strings.|


## Example Usage

```c
#include "shell.h"

int main(void)
{
    char **args;
    token_t *path_tokens;

    /* Example usage of _getenv */
    path_tokens = _getenv("PATH");

    /* Example usage of _stat_checker */
    token_t *cmd_tokens = tokenicer("ls -l", " ");
    cmd_tokens = _stat_checker(cmd_tokens, path_tokens);

    /* Example usage of _list_to_array */
    args = _list_to_array(cmd_tokens);

    /* Example usage of _EXE_Cute */
    _EXE_Cute(args);

    /* Don't forget to free memory when done */
    free_list(path_tokens);
    free(args);

    return 0;
}
```

## Contributing

Contributions are welcome. Please fork the repository and submit a pull request with your changes.

## Installation

To compile the project, ensure you have a C compiler compatible with the GNU89 standard. Clone the repository and compile the code using `gcc`.

```bash
git clone git@github.com:Pirataninja777/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```
## Usage

Run the program with:

```bash
./simple_shell
