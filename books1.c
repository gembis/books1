/*
 * UPPGIFT BOOKS1
 *
 * Börja med att läsa igenom koden och försök få en uppfattning om vad den gör.
 * Därefter går ni över till del ett och därefter del två (del 3 kan ni vänta
 * med tills vi gått igenom hur man delar upp kod i olika .c-filer).
 *
 * DEL ETT:
 *  I denna kod finns ett antal avsiktliga programmeringsfel. Rätta dem ett i taget
 *  tills GCC kan kompilera koden utan errors eller warnings. Programmet ska även
 *  fungera på så vis att det inte hänger sig eller kraschar när man kör det.
 *
 * DEL TVÅ:
 *  Det saknas kod för funktionerna addbook(), listbooks() och search(). Uppgiften
 *  går ut på att skapa dessa funktioner så att programmet blir komplett och fungerar
 *  som det är tänkt.
 *
 * DEL TRE:
 *  Dela upp din kod i fem filer:
 *   1. books1.h: Alla #includes och eventuella #defines samt strukturer och globala variabler.
 *                I denna fil lägger ni även alla funktionsdeklarationer.
 *   2. books1.c: optionloop() och main()
 *   3. addbook.c: addbook()
 *   4. listbooks.c: listbooks()
 *   5. search.c: search()
 *  Kompilera alla .c-filer individuellt och länka ihop dem till en färdig programbinär.
 *
 * REDOVISNING:
 *  Muntligt för lärare
 *
 *
*/
#include "books1.h"

/* s, t: two strings; ls, lt: their respective length */
int levenshtein(const char *s, int ls, const char *t, int lt)
{
        int a, b, c;

        /* if either string is empty, difference is inserting all chars 
         * from the other
         */
        if (!ls) return lt;
        if (!lt) return ls;

        /* if last letters are the same, the difference is whatever is
         * required to edit the rest of the strings
         */
        if (s[ls - 1] == t[lt - 1])
                return levenshtein(s, ls - 1, t, lt - 1);

        /* else try:
         *      changing last letter of s to that of t; or
         *      remove last letter of s; or
         *      remove last letter of t,
         * any of which is 1 edit plus editing the rest of the strings
         */
        a = levenshtein(s, ls - 1, t, lt - 1);
        b = levenshtein(s, ls,     t, lt - 1);
        c = levenshtein(s, ls - 1, t, lt    );

        if (a > b) a = b;
        if (a > c) a = c;

        return a + 1;
}

/* functions */

void optionloop(int mSize)
{
        int option;

        printf("\n"
                "1. Add book\n"
                "2. List all books\n"
                "3. Search\n"
                "4. Exit\n"
                "\n> ");
        fflush(stdout);
        scanf("%d", &option);
        getchar();

        switch (option)
        {
                case 1:
                 numberOfBooks++;
                 addbook(mSize);
                 return;
                case 2:
                 listbooks();
                 break;
                case 3:
                 search();
                 break;
                case 4:
                 free(books);
                 exit(0);
        }

        return;
}

/* MAIN */
int main()
{
    int size;

    /* allocate memory */
    numberOfBooks = 1;
    size = sizeof(struct Book) * numberOfBooks;
    books = malloc(size);

    /* add the first book statically. the rest will be added dynamically by the user */
    strncpy(books[0].title, "Dice man", 31);
    strncpy(books[0].author, "Luke Rhinehart", 31);
    books[0].pages = 500;

    /* the main option loop */
    while (1){
        optionloop(size);    
    }

    return 0;
}
