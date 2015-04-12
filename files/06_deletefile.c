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
            fprintf(stderr, "%s does not exist! Please try again.\n", filename);
            exit(1);
        } else {
            fclose(deleteme);
            printf("Are you sure you want to delete %s? This action cannot be "
                "undone.\nPress Y to continue or an other key to abort.\n",
                filename);
            scanf("%c", &confirmation);
            if (confirmation == 'y' || confirmation == 'Y') {
                remove(filename);
                // check if file was indeed deleted
                // (remove might fail due to missing permissions)
                if ((deleteme = fopen(filename, "r")) != NULL) {
                    fprintf(stderr, "Deletion of %s was unsuccessful.\n"
                            "Make sure you have the necessary permissions for "
                            "its parent directory.\n", filename);
                    exit(1);
                } else {
                    fprintf(stderr, "%s deleted successfully.\n", filename);
                }
            } else {
                printf("Deletion of %s aborted.\n", filename);
            }
        }
    }
    return 0;
}
