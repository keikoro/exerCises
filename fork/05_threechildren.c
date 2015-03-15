/*
 *  threechildren.c
 *
 *  A "Hello, world" program with one parent and three child processes.
 *  One child prints "Hello", another "world", and the third ", ";
 *  their parent waits for them, then finishes by printing "!" and a newline.
 *
 *  Since processes run in parallel, it's not the point of this program
 *  to print out "Hello, world" in the correct order.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t ch1, ch2, ch3, wpid;
    int status = 0;
    int a[3] = {0};

    if ((ch1 = fork()) > 0) {
        a[0] = ch1;
    } else if (ch1 == 0) {
        printf("Hello");
        sleep(1);
        exit(EXIT_SUCCESS);
    }

    if ((ch2 = fork()) > 0) {
        a[1] = ch2;
    } else if (ch2 == 0) {
        printf(", ");
        sleep(1);
        exit(EXIT_SUCCESS);
    }

    if ((ch3 = fork()) > 0) {
        a[2] = ch3;
    } else if (ch3 == 0) {
        printf("world");
        sleep(1);
        exit(EXIT_SUCCESS);
    }

    // wait for all child processes to be finished
    // only then print the exclamation mark and newline
    while ( (wpid = waitpid(a[0], &status, 0)) == 0) {
    }
    while ( (wpid = waitpid(a[1], &status, 0)) == 0) {
    }
    while ( (wpid = waitpid(a[2], &status, 0)) == 0) {
    }

    printf("!\n");

    return 0;
}