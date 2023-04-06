/*search.c*/

#include "books1.h"

void search()
{
        char *p;
        char strToCmp[100];
        printf("Search for book:\n> ");
        fgets(strToCmp, 99, stdin);
        for (p = strToCmp + 1; *p; p++)
        {
                *p = tolower(*p);
        }

        char *searchTit;
        char *searchAut;
        int *distance;
        int saved = 60;
        int size = sizeof(distance) * numberOfBooks;
        distance = malloc(size);

        for (int i = 0; i < numberOfBooks; i++)
        {
                distance[i] = levenshtein(strToCmp, strlen(strToCmp), books[i].title, strlen(books[i].title));
                // DEBUG // printf("Difference between '%s' and '%s': %d\n", strToCmp, books[i].title, distance[i] - 1);
                if (distance[i] < saved){
                        saved = distance[i];
                        searchTit = books[i].title;
                        searchAut = books[i].author;
                }

        }

        char response[64];
        while(response[0] != 'y' || response[0] != 'Y' || response[0] != 'n' || response[0] != 'N'){
                printf("Were you looking for the book '%s' by author %s? (y/n)\n> ", searchTit, searchAut);
                fgets(response, 63, stdin);

                if(response[0] == 'y' || response[0] == 'Y'){
                        printf("Great! Woohoo!!\n");
                        break;
                }
                else if(response[0] == 'n' || response[0] == 'N'){
                        printf("Well... Take it or leave it I guess..!\n");
                        break;
                }
                else{
                        printf("Not a valid answer...\n");
                        s(1);
                        printf("Try again!\n");
                        s(1);
                        continue;
                }
        }

        return;
}