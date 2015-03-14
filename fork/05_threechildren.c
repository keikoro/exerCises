/*
 *  threechildren.c
 *
 *  A "Hello, world" program with one parent and three child processes.
 *  One child prints "hello", another "world", and the third ", ";
 *  their parent waits for them, then finishes by printing "!" and a newline.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t ch1, ch2, ch3, waitpid;
    int status = 0;

    if (fork() == 0) {
        printf("Hello");
    }
    if (fork() == 0) {
        printf(", ");
    }
    if (fork() == 0) {
        printf("world");
    }

    wait(&status);
    printf("!\n");

    return 0;
}