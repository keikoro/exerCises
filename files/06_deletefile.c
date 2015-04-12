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
        char confirmation;

        if ((deleteme = fopen(filename, "r")) == NULL) {
            fprintf(stderr, "File to delete does not exist! Please try again.\n");
            exit(1);
        } else {
            printf("Are you sure you want to delete %s? "
                    "Press y to continue or an other key to abort.\n", filename);
            scanf("%c", &confirmation);
            if (confirmation == 'y' || confirmation == 'Y') {
                printf("About to delete the file...\n");
            } else {
                printf("Deletion aborted.\n");
            }
        }
    }
    return 0;
}
