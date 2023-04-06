/*books1.h*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define s(int) sleep(int)

/* structures */
struct Book
{
    char title[64];
    char author[64];
    int pages;
};

void listbooks();

void addbook(int size);

void search();

int levenshtein(const char *s, int ls, const char *t, int lt);

/* global variables */
int numberOfBooks;
struct Book *books;