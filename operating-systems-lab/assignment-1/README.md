# Your first assignment from the book Operating systems - Three Easy Pieces
## General Instructions
It is mandatory that you attempt the exercise by yourself, you will only have access
to the linux man pages and any number of books, but using the internet to search for
answers is strictly prohibited and the assignment will be considered invalid.

You have to submit the C file of the code along with the attempted picture on a paper.
It is important for you to sit with a pen and paper while doing these exercises.

## Questions
1. Write a program that calls `fork()`, before calling `fork()` declare a variable and set it's value.
Check the value of the variable in both the parent and child process and interpret the result.

2. Write a program that opens a file (with the `open()` system call) and then calls `fork()`
to create a new process, can both the child and parent access the fd? what happens when
they're writing to the same fd concurrently?
