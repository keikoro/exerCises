/*
 *  openafile.c
 *
 *  A program demonstrating basic file opening with C.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *input;
    char filename[] = "demo.txt";
    char *inputfile = (char*)malloc(256*sizeof(char));
    inputfile = &filename[0];

    if ((input = fopen(inputfile, "r")) != NULL) {
        printf("Success!\n");
    } else {
        fprintf(stderr, "Cannot open input file %s\n", inputfile);
        exit(1);
    }

    return 0;
}