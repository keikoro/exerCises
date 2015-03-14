/*
 *  basicfork.c
 *
 *  A program demonstrating basic forking:
 *  splitting a child process from a parent process with fork()
 */

#import <stdio.h>
#import <unistd.h>

int main()
{
    int child_pid;
    child_pid = fork();

    printf("starting... \n");
    printf("child pid: %i\n", child_pid);
    sleep(2);
    printf("child pid: %i\n", child_pid);
    sleep(2);
    printf("child pid: %i\n", child_pid);
    printf("stopping... \n");

    return 0;
}