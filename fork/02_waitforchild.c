/*
 *  basicfork.c
 *
 *  A program demonstrating basic forking:
 *  splitting a child process from a parent process with fork();
 *  also includes process IDs
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;
    child_pid = fork();

    // child process
    if(child_pid == 0) {
        printf("------------\n");
        printf("this is child process %d\n", getpid());
        printf("its parent is: %d\n", getppid());
        exit(EXIT_SUCCESS);

    // parent process
    } else if (child_pid > 0) {
        sleep(4);
        printf("------------\n");
        printf("this is the parent process, its PID is %d\n", getpid());
        printf("its child is %d\n", child_pid);
        wait(NULL); // waits for the child to finish before finishing

    // error while forking
    } else {
        perror("An error occourred.");
        exit(EXIT_FAILURE);
    }

    return 0;
}