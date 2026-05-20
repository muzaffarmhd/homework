#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int  ret;
    ret = execl("/bin/ls", "-a", (char *) NULL);
    if (ret == -1) {
        fprintf(stderr, "Failed to execute the program");
        exit(1);
    }
}