//
// Created by muzaffar on 5/15/26.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, int* argv[]) {
    int x, pid;
    x = 100;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "There was an error while forking. ");
    } else if (pid == 0) {
        fprintf(stdout, "Hello I am child process and my corresponding x value is %d\n", x);
    } else {
        fprintf(stdout, "Hello I am parent process and my corresponding x value is %d\n", x);
    }
}