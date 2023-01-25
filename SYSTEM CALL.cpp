#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid, parent_pid;

    child_pid = fork();
    if (child_pid == 0) {
        printf("I am the child process.\n");
        printf("My process ID is: %d\n", getpid());
        printf("My parent's process ID is: %d\n", getpid());
    }
    else {
        printf("I am the parent process.\n");
        printf("My process ID is: %d\n", getpid());
        printf("My child's process ID is: %d\n", child_pid);
    }

    return 0;
}

