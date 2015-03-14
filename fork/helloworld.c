/*
 *  helloworld.c
 *
 *  A program with two processes:
 *  The child process prints "Hello", the parent process prints "world".
 *  The parent waits for the child process to finish, then finishes with "\n".
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
    int child_pid;

    // parent process
    if((child_pid = fork()) > 0)
    {
        sleep(10);
        printf("parent process\n");
    }
    // child process
    else if (child_pid == 0)
    {
        printf("child process\n");
        printf("my pid is %d\n", getpid());
        printf("my parents pid is %d\n", getppid());
        sleep(12);
        printf("child process\n");
    }
    // error
    else
    {
        perror("An error occourred.");
        exit(1);
    }

    return 0;
}