/*
 *  threewaitingchildren.c
 *
 *  A "Hello, world" program with one parent and three child processes.
 *  One child prints "Hello", another "world", and the third ", ";
 *
 *  Each child waits for the next to finish before finishing itself; their
 *  parent waits for all of them to finish, then prints a "!" and a newline.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t ch1, ch2, ch3, wpid;
    int status = 0;
    int blank = 0;
    int *(a[3]) = {0};


    // parent process
    if ((ch1 = fork()) > 0) {
        a[0] = &ch1;
        sleep(1);
        // wait for child 1 to finish
        while ( (wpid = waitpid(*(a[0]), &status, 0)) == 0) {
        }
        printf("!\n");

    // spawn child 1
    } else if (ch1 == 0) {

        if ((ch2 = fork()) > 0) {
            a[1] = &ch2;
            sleep(1);
            // wait for child 2 to finish
            while ( (wpid = waitpid(*(a[1]), &status, 0)) == 0) {
            }
            printf("world");
            exit(EXIT_SUCCESS);

        // spawn child 2
        } else if (ch2 == 0) {

            if ((ch3 = fork()) > 0) {
                a[2] = &ch3;
                sleep(3);
                // wait for child 3 to finish
                while ( (wpid = waitpid(*(a[2]), &status, 0)) == 0) {
                }
                printf(", ");
                exit(EXIT_SUCCESS);

            // spawn child 3
            } else if (ch3 == 0) {
                sleep(1);
                printf("Hello");
                exit(EXIT_SUCCESS);
            }
        }
    }

    return 0;
}