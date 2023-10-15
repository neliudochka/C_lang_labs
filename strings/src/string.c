#include<stdio.h>
#include<stdlib.h>

#include "string.h"

char * get_input(size_t * nChar) {
    char * input = NULL;
    size_t len = 0;
    *nChar = 0;

    printf("Please, enter string: \n");
    *nChar = getline(&input, &len, stdin);
    *nChar = *nChar -1;

    return input;
}

char modify_char(char c) {
    int A_ANSCII = 65;
    int Z_ANSCII = 90;
    int a_ANSCII = 97;
    int z_ANSCII = 122;
    int diff = 32;
    if ((A_ANSCII<=c)&&(c<=Z_ANSCII)) {
        //all odd characters uppercase
        if (c%2 == 0) {
            return (c+diff);
        }
    }
    if((a_ANSCII<=c)&&(c<=z_ANSCII)) {
        // and even characters lowercase
        if(c%2 == 1) {
            return (c-diff);
        }
    }
    return c;
}
char * modify_string(char * str, size_t nChar) {
    for (int i = 0; i < nChar; i++) {
        str[i] = modify_char(str[i]);
    }
    return str;
}
