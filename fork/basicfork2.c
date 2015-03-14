/*
 *  basicfork.c
 *
 *  A program demonstrating basic forking:
 *  splitting a child process from a parent process with fork();
 *  also includes process IDs
 */

#import <stdio.h>
#import <stdlib.h>
#import <unistd.h>

int main()
{
    int child_pid;

    switch(child_pid = fork()) {

        // error
        case -1:
            perror("something went wrong...\n");
            exit(0);

        // child process
        case 0:
            printf("this is the child process\n");

        // parent process
        default:
            printf("this is the parent process\n");
    }

    return 0;
}