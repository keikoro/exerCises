/*
 *  deletefile.c
 *
 *  A program for deleting files.
 *
 *  Usage: deletefile file2delete
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *deleteme;
    char *filename;

    // print usage message if not enough arguments were provided
    if (argc < 2) {
        printf("Usage: deletefile file2delete\n");
    } else {
        // check that file exists
        filename = argv[1];

        if ((deleteme = fopen(filename, "r")) == NULL) {
            fprintf(stderr, "File to delete does not exist! Please try again.\n");
            exit(1);
        } else {
        }

    }

    return 0;
}