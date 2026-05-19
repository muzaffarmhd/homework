#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int fd, pid;
    char* path = "/home/muzaffar/personal/homework/test.md";
    fd = open(path, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "There was an error in opening the file: %d\n", errno);
        _exit(1);
    }
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "There was an error in forking the process\n");
        _exit(1);
    } else if (pid == 0) {
        fprintf(stdout, "I'm child and I am writing to the file fd %d\n", fd);
        char child_content[] = "hello, world from child\n";
        int out = write(fd, child_content, sizeof(child_content));
        if (out < 0) {
            fprintf(stderr, "There was an error in writing to the file from the child\n");
        } else {
            fprintf(stdout, "Write to the file from child was successful\n");
        }
    } else {
        fprintf(stdout, "I'm Parent and I am writing to the file fd %d\n", fd);
        char parent_content[] = "hello, world from parent\n";
        int out = write(fd, parent_content, sizeof(parent_content));
        if (out < 0) {
            fprintf(stderr, "There was an error in writing to the file from the child\n");
        } else {
            fprintf(stdout, "Write to the file from parent was successful\n");
        }
    }
}