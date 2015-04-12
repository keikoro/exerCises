/*
 *  createfile.c
 *
 *  A program demonstrating creating new files.
 *
 *  The program checks for the existence of a file whose name is
 *  provided by the user via the command line. If the file does not
 *  yet exist, it is created on the spot.
 *  The user can additionaly provide text to be written into the file
 *  on creation.
 *
 *  Usage: createfile filename [content]
 */

#include <stdio.h>
#include <stdbool.h>

bool checkfile(int argc, char* argv[]);

int main(int argc, char *argv[])
{

    checkfile(argc, argv);

    return 0;
}

bool checkfile(int argc, char* argv[]) {
        return true;
    }
