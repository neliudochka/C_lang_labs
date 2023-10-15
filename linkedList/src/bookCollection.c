#include<stdio.h>
#include<stdlib.h>

#include<malloc.h>
#include <string.h>

#include "bookCollection.h"

BookCollection* book_init ( char *title, 
                            float price, 
                            unsigned int nPages,
                            char *language,
                            float weight,
                            unsigned int year) {
    BookCollection* tail_p;
    tail_p = malloc(sizeof(BookCollection));
    //string
    tail_p->title = title;
    tail_p->price = price;
    tail_p->nPages = nPages;
    //string
    tail_p->language = language;
    tail_p->weight = weight;
    tail_p->year = year;
    tail_p->next = NULL;
    return tail_p;
}

BookCollection* book_add(   char *title, 
                            float price, 
                            unsigned int nPages,
                            char *language,
                            float weight,
                            unsigned int year,
                            BookCollection *tail_p) {

    BookCollection* new_tail_p = book_init(title,
                                            price, 
                                            nPages,
                                            language,
                                            weight,
                                            year);
    new_tail_p->next = tail_p;
    return new_tail_p;
}

void bookCollection_print(BookCollection *tail_p) {
    if (tail_p == NULL)
        printf("cur_p = %p\n", tail_p);

    while (tail_p != NULL) {
        //printf("cur_p = %p, next = %p\n", tail_p, (void*)tail_p->next);
        printf("Title: %s\n",tail_p->title);
        printf("\tprice: %f UAN\n", tail_p->price);
        printf("\tnumber of pages: %i\n", tail_p->nPages);
        printf("\tlanguage: %s\n", tail_p->language);
        printf("\tweight: %f kg\n", tail_p->weight);
        printf("\tyear of publication: %i\n\n", tail_p->year);
    
        tail_p = tail_p->next;
    }
}


BookCollection* book_delete(BookCollection *tail_p) {
    BookCollection* next_p;
    next_p = tail_p->next;
    if (tail_p)
        free(tail_p);
    return next_p;
}

void bookCollection_delete(BookCollection** tail_p) {
    BookCollection* current = *tail_p;
    while (current != NULL) {
        current = book_delete(current);
    }
    *tail_p = NULL;
}

//supporting func
char* stringcpy(const char* original) {
    int size = strlen(original) ;
    char* copy = malloc(size + 1);

    int i;
    for(i = 0; original[i] != '\0'; i++) {
        copy[i] = original[i];
    }
    copy[i]=0;
    return copy;
}


BookCollection* create_bookCollection(char * filename){
    //беремо інфу з файлику
    BookCollection *bookCollection = NULL;
    char *title;
    float price;
    unsigned int nPages;
    char *language;
    float weight;
    unsigned int year;

    FILE *fp;
	char ch;
    fp = fopen(filename,"r");
    if ( !fp )
    {
        printf("file %s does not exist\n", filename);
    }
    else
    {
        //write content to the dyn_string
        char *full_text;
        full_text = (char*)malloc(sizeof(char));
        int i = 0, j = 1, nLines = 0;
        char delim[] = "_";
        while ( (ch = fgetc(fp)) != EOF )
            {
                full_text = (char*)realloc(full_text, j * sizeof(char));
                full_text[i] = ch;
                if(full_text[i-1] == '\n') {
                    full_text[i-1] = '_';
                    nLines++;
                }
                i++;
                j++;
            }
        fclose(fp);
        
        char * price_str;
        char * nPages_str;
        char * weight_str;
        char * year_str;
        
        char *ptr = strtok(full_text, delim);
        for(; nLines >= 0; nLines--) {
            title = stringcpy(ptr);
            ptr = strtok(NULL, delim);

            price_str = stringcpy(ptr);
            ptr = strtok(NULL, delim);

            nPages_str = stringcpy(ptr);
            ptr = strtok(NULL, delim);

            language = stringcpy(ptr);
            ptr = strtok(NULL, delim);

            weight_str = stringcpy(ptr);
            ptr = strtok(NULL, delim);

            year_str = stringcpy(ptr);
            ptr = strtok(NULL, delim);

            sscanf(price_str, "%f", &price);
            sscanf(nPages_str, "%i", &nPages);
            sscanf(weight_str, "%f", &weight);
            sscanf(year_str, "%i", &year);

            bookCollection = book_add(title, price, nPages, language, weight, year, bookCollection);
        }
        free(full_text);
	}
    return bookCollection;
}
