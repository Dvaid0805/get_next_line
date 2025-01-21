# 📖 get_next_line 📖

> This repository contains "get_next_line" project that is part of the École 42 curriculum.

`get_next_line` is a project aimed at coding a function that reads a file descriptor and returns one line at a time from the file. This project enhances skills in file I/O, string handling, and memory management in C.

## ✏️ What does it do?

The `get_next_line()` function reads a file descriptor, returns the next line found as a string on each call, and efficiently handles multiple simultaneous file descriptors (bonus part).

## 🎯 Key aspects

- Opening, reading from, and closing file descriptors
- Buffering file content in a static variable across calls
- Tokenizing a line from the buffer and returning it
- Ensuring it works for any file size with dynamic memory allocation
- Thread safety to allow concurrent reading of multiple files (bonus part)


## 🛠 Getting started

- Create a `main.c` and execute the function there. Execute `vim main.c` and paste the following content:
```c
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", 0);
    while (1)
    {
        str = get_next_line(fd);
        printf ("line: %s", str);
        if (!str)
            break ;
        free(str);
    }
	return (0);
}
```
- Dont forget to create a file that function will read. Execute this command to create this file:
```bash
head -c 1000 /dev/urandom | base64 | fold -w 80 | head -n 10 > test.txt
```
## 💧 Leaks
To check for memory leaks, you can use one of the following methods:
1. Valgrind:
- Install it if you don't have it, [GitHub Page](https://github.com/LouisBrunner/valgrind-macos).
- Compile your program with `-g3` flag and run it as follows:
```bash
valgrind --leak-check=yes "your_executable_here"
```
2. atexit() function inside your main:
Modify your main as follows:
```bash
#include "get_next_line.h"

void	ft_leaks(void)
{
	system ("leaks -q executable_name");
}

int	main(void)
{
	int		fd;
	char	*str;

    atexit(ft_leaks);
	fd = open("test.txt", 0);
    while (1)
    {
        str = get_next_line(fd);
        printf ("line: %s", str);
        if (!str)
            break ;
        free(str);
    }
	return (0);
}
```
3. atexit during program startup:
In this case, you can launch your program with the following flags:
```bash
leaks -atExit -- ./executable_file
```

## 🚀 Conclusion

Congratulations, you've now mastered the art of getting the next line! May your code flow smoothly like a well-written novel. Happy coding! 🚀

