/*
 *  helloworld.c
 *
 *  A program with two processes:
 *  The child process prints "Hello", the parent process prints "world".
 *  The parent waits for the child process to finish, then finishes with "\n".
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int child_pid;

    // child process
    if((child_pid = fork()) == 0) {
        printf("Hello ");

    // parent process
    } else if (child_pid > 0) {
        // wait for child process to print
        usleep(1000);
        printf("world");
        // print newline only when child process is finished
        wait(NULL);
        printf("\n");

    // error
    } else {
        perror("An error occourred.");
        exit(1);
    }

    return 0;
}