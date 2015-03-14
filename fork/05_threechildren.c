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

    if ((ch1 = fork()) == 0) {
        printf("Hello");
    } else {
        printf("parent, ch1 started\n");
    }

    if ((ch2 = fork()) == 0) {
        printf(", ");
    } else {
        printf("parent, ch2 started\n");
    }

    if ((ch3 = fork()) == 0) {
        printf("world");
    } else {
        printf("parent, ch3 started\n");
    }

    wait(&status);
    printf("!\n");

    return 0;
}