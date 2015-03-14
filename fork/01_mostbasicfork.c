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

    // depending on the process we're in
    // the output for child_pid is either 0 (for the child)
    // or a number > 0 (for the parent)
    printf("value of child_pid: %i\n", child_pid);
    sleep(2);
    printf("value of child_pid: %i\n", child_pid);
    sleep(2);
    printf("value of child_pid: %i\n", child_pid);
    printf("stopping... \n");

    return 0;
}