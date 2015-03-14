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
    child_pid = fork();

    // parent process
    if(child_pid > 0) {
        sleep(4);
        printf("this is the parent process\n");
        printf("the parent's PID is: %d\n", getpid());
        printf("its child's PID is: %d\n", child_pid);
        sleep(2);

    // child process
    } else if (child_pid == 0) {
        sleep(2);
        printf("this is the child process\n");
        printf("the child's PID is: %d\n", getpid());
        printf("its parent's PID is: %d\n", getppid());
        sleep(2);

    // error while forking
    } else {
        perror("An error occourred.");
        exit(1);
    }

    return 0;
}