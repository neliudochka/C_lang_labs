#include<stdio.h>
#include<stdlib.h>
#include "bookCollection.h"


int main(){
	char filename[] = "HarryPotterSeries.txt";

    BookCollection *bookCollection = create_bookCollection(filename);
    printf("Harry Potter Books Collection: \n");
    bookCollection_print(bookCollection);
    bookCollection_delete(&bookCollection);
    return 0;
}