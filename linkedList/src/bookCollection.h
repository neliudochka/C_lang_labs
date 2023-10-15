typedef struct Book {
    char *title;
    float price;
    unsigned int nPages;
    char *language;
    float weight;
    unsigned int year;
    double info;
    struct Book * next;
} BookCollection;

BookCollection* book_add(   char *title, 
                            float price, 
                            unsigned int nPages,
                            char *language,
                            float weight,
                            unsigned int year,
                            BookCollection *tail_p);

void bookCollection_print(BookCollection *tail_p);


BookCollection* book_delete(BookCollection *tail_p);

void bookCollection_delete(BookCollection** tail_p);

BookCollection* create_bookCollection(char * filename);