#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pid;
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret != 0) {
        fprintf(stderr, "Pipe fail!");
        exit(1);
    }
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "There was an error in forking the process\n");
    } else if (pid == 0) {
        char child_content[] = "Hello!";
        fprintf(stdout, "Hello!\n");
        write(pipefd[1], child_content, sizeof(child_content));
    } else {
        char parent_content[sizeof("Goodbye!")];
        read(pipefd[0], parent_content, sizeof(parent_content));
        fprintf(stdout,"Goodbye!\n");
    }
}