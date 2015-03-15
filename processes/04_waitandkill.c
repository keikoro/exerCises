/*
 *  waitandkill.c
 *
 *  A program with a parent and a child process;
 *  the parent waits for the child to finish, or, alternatively, kills it,
 *  and then outputs the return code or kill signal.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// needs to be included for wait() (though not for wait(NULL))
#include <sys/wait.h>
#include <signal.h>


int main()
{
    pid_t child_pid;
    int status = 0;

    // parent
    if ((child_pid = fork()) > 1) {
        printf("in parent, child_pid is %d\n", child_pid);
        printf("in parent, status: %d\n", status);

        kill(child_pid, SIGKILL); // kill the child

        wait(&status);
        // if child exited normally
        if (WIFEXITED(status)) {
            printf("child %d exited with return code %d\n", child_pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("child %d was killed with signal %d\n", child_pid, WTERMSIG(status));
        }

    // child_pid
    } else if (child_pid == 0) {
        printf("in child_pid, pid is %d\n", getpid());
        printf("in child_pid, status: %d\n", status);
        exit(EXIT_SUCCESS);

    // error
    } else {
        perror("There was a problem forking!");
        exit(EXIT_FAILURE);
    }

    return 0;
}