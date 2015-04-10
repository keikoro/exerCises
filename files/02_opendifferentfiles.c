/*
*  opendifferentfiles.c
*
*  A program for opening user-provided files.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCHARS 255

int main() {

    FILE *input;
    char *inputfile = (char*)malloc(256*sizeof(char));

    printf("Please provide the name of a file to be opened:\n");
    fgets(inputfile, MAXCHARS, stdin);

    if ((input = fopen(inputfile, "r")) != NULL) {
        printf("Success, file %s exists!\n", inputfile);
    } else {
        fprintf(stderr, "Cannot open input file %s\n", inputfile);
        exit(1);
    }

    return 0;
}