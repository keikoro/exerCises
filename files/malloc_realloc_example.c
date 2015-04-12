#include <stdlib.h>

#define BIG_NUMBER 1024
#define SMALL_NUMBER 16

struct msg
{
    int code;
    char message[BIG_NUMBER];
};

int main(void)
{
    char* buffer;
    struct msg* messagelist;

    /* Allocate some memory from the heap */
    buffer = (char*)malloc(BIG_NUMBER);
    if (buffer != NULL)
    {
        /* I can use the memory safely */
    }

    /* Reduce the size of the memory */
    char* smallbuffer = (char*)realloc(buffer, SMALL_NUMBER);
    if (smallbuffer != NULL)
    {
        /* I can use the memory safely */
    }

    /*******************************************
     * NOTE: Look carefully at the realloc call above.
     * If the call to realloc had failed and I had assigned
     * it to the original buffer like so:
     *     buffer = (char*)realloc(buffer, SMALL_NUMBER);
     * then my buffer would have been set to NULL and I would
     * not only lose access to the data that was stored
     * there, but I'd create a memory leak too!
     *******************************************/

    /* Allocate some memory from the heap */
    messagelist = (struct msg*)calloc(SMALL_NUMBER, sizeof(struct msg));
    if (messagelist != NULL)
    {
        /* I can use the memory safely */
    }

    /* Remember to clear up after myself */
    free(smallbuffer);
    free(messagelist);

    /* NOTE: I DON'T need to free the 'buffer' variable */
    /* because realloc already did it for me <img src="http://www.fayewilliams.com/wp-includes/images/smilies/icon_smile.gif" alt=":-)" class="wp-smiley"> */

    return EXIT_SUCCESS;
}