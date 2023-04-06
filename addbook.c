/*addbook.c*/

#include "books1.h"

void addbook(int sizeUpd)
{
        sizeUpd = sizeof(struct Book) * numberOfBooks;
        books = realloc(books, sizeUpd);

        printf("Title:\n");
        fgets(books[numberOfBooks - 1].title, 63, stdin);
        int tempTit = strlen(books[numberOfBooks - 1].title);
        books[numberOfBooks - 1].title[tempTit - 1] = 0;

        printf("\nAuthor's name:\n");
        fgets(books[numberOfBooks - 1].author, 63, stdin);
        int tempAut = strlen(books[numberOfBooks - 1].author);
        books[numberOfBooks - 1].author[tempAut - 1] = 0;

        printf("\nNumber of pages:\n");
        scanf("%d", &books[numberOfBooks - 1].pages);

        return;
}