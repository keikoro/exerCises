/*
 *  openfilewithargument.c
 *
 *  A program demonstrating opening a file from the command line
 *  by providing the file name as an argument.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 255

int main(int argc, char *argv[])
{
    FILE *f;

    // check if there are enough command line arguments
    // and print out usage message if necessary
    if (argc != 2) {
        printf("Usage: openfilewithargument filename\n");
    } else {
        char *inputfile = (char *) malloc(MAXLENGTH * sizeof(char));
        inputfile = argv[1];

        if ((f = fopen(inputfile, "r")) != NULL) {
            printf("Success! File %s exists!\n", inputfile);
            fclose(f);
        } else {
            fprintf(stderr, "Cannot open input file %s\n", inputfile);
            exit(1);
        }
    }

    return 0;
}