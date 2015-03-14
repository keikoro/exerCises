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

    // child process
    if(child_pid == 0) {
        printf("------------\n");
        printf("this is child process %d\n", getpid());
        printf("its parent is: %d\n", getppid());
        sleep(2);

    // parent process
    } else if (child_pid > 0) {
        sleep(4);
        printf("------------\n");
        printf("this is the parent process, its PID is %d\n", getpid());
        printf("its child is %d\n", child_pid);
        sleep(2);

    // error while forking
    } else {
        perror("An error occourred.");
        exit(1);
    }

    return 0;
}