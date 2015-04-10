/*
 *  opendifferentfiles.c
 *
 *  A program for opening user-provided files.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHARS 255

int main() {

    FILE *input;
    char *inputfile = (char*)malloc(256*sizeof(char));

    printf("Please provide the name of/path to a file to be opened:\n");
    fgets(inputfile, MAXCHARS, stdin);

    // get rid of newline in inputfile (caused by fgets)
    // by replacing it with null terminator
    size_t flength = strlen(inputfile);
    if (inputfile[flength - 1] == '\n') {
        inputfile[flength - 1] = '\0';
    }

    if ((input = fopen(inputfile, "r")) != NULL) {
        printf("Success, file %s exists!\n", inputfile);
    } else {
        fprintf(stderr, "Cannot open input file %s\n", inputfile);
        exit(1);
    }

    return 0;
}