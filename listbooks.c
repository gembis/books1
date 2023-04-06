/*listbooks.c*/

#include "books1.h"

void listbooks()
{
    printf("\nLibrary size: %d book(s)\n\n", numberOfBooks);

    for (int i = 0; i < numberOfBooks; i++)
    {
        printf("%d. %s - %s (%d pages)\n", i+1, books[i].title, books[i].author, books[i].pages);
    }

    return;
}