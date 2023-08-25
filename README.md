# 📖 get_next_line 📖

get_next_line is a project to code a function that reads a file descriptor and returns one line at a time from the file. This develops skills in file I/O, string handling and memory management in C.

## ✏️ What does it do?

The get_next_line() function reads a file descriptor, returns the next line found as a string each call, and handles multiple simultaneous file descriptors efficiently. 

## 🎯 Key aspects

- Opening, reading from and closing file descriptors
- Buffering file content in a static variable across calls  
- Tokenizing a line from the buffer and returning it
- Ensuring it works for any file size with dynamic memory allocation
- Thread safety to allow concurrent reading of multiple files

## 🎓 Skills developed

- File I/O, data buffering, string parsing and arrays of pointers
- Recursive functions and complexity optimization
- Static variables and memory management

Mastering this project provides a solid foundation for core C programming concepts. Let me know if any part needs more explanation!

## 🛠 Getting started

To compile:

<code> gcc main.c get_next_line.c get_next_line_utils.c -o get_next_line -D BUFFER_SIZE=100 </code>

This builds the executable with a buffer size of 100 bytes.
