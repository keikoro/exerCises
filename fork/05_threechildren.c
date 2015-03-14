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
        sleep(1);
        exit(EXIT_SUCCESS);
    }

    if ((ch2 = fork()) == 0) {
        printf(", ");
        sleep(1);
        exit(EXIT_SUCCESS);
    }

    if ((ch3 = fork()) == 0) {
        printf("world");
        sleep(1);
        exit(EXIT_SUCCESS);
    }

    while (wait(&status) > 0) {
        // wait for all children processes to be finished
    }

    printf("!\n");

    return 0;
}