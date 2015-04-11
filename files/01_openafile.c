/*
 *  openafile.c
 *
 *  A program demonstrating basic file opening with C.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXCHARS 255

int main()
{

    FILE *f;
    char filename[] = "demo.txt";
    char *inputfile = (char *) malloc(MAXCHARS * sizeof(char));
    inputfile = &filename[0];

    if ((f = fopen(inputfile, "r")) != NULL) {
        printf("Success! demo.txt exists!\n");
        fclose(f);
    } else {
        fprintf(stderr, "Cannot open input file %s\n", inputfile);
        exit(1);
    }

    return 0;
}