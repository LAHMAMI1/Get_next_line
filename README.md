# Get_next_line

Get_next_line is a project that focuses on implementing a function that reads a line from a file descriptor. This function is designed to simplify the process of reading files or input, making it more convenient for developers to handle data line by line in C.

## Table of Contents

- [Introduction](#introduction)
- [Goals](#goals)
- [Mandatory Functionality](#mandatory-functionality)
- [Bonus Features](#bonus-features)
- [Compilation](#compilation)
- [Usage](#usage)

## Introduction

The `Get_next_line` project introduces a function that returns a single line from a file descriptor. It also helps developers learn about static variables, which play a key role in maintaining state between function calls. By completing this project, we will gain a better understanding of memory management, file reading, and static variables in C.

## Goals

- Write a function that reads from a file descriptor one line at a time.
- Learn and implement static variables to handle consecutive calls to the function.
- Ensure the function behaves correctly for both file inputs and standard input.

## Mandatory Functionality

You must implement the following function:

```c
char *get_next_line(int fd);
```
### Key Requirements:

- Your function must read a line from a file descriptor each time it is called.
- The function should return `NULL` when there's nothing left to read or when an error occurs.
- The function must handle both files and standard input.
- The line returned must include the newline character `\n`, except when at the end of the file.
- You must compile your code with a configurable buffer size, for example:

  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
  ```
## Bonus Features

If you complete the mandatory part, you can implement the following bonus features:

- **Multiple File Descriptors**: Implement the ability to handle multiple file descriptors. For example, the function should allow reading from different file descriptors (e.g., fd 3, 4, 5) without losing track of the lines being read from each.

## Compilation

To compile the project with a buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<your_value> get_next_line.c get_next_line_utils.c -o get_next_line
```

## Usage

Include `get_next_line.h` in your project and call the function to read lines from a file or standard input.

Example usage:

```c
#include "get_next_line.h"

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
