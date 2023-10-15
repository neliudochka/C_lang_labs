#include<stdio.h>
#include<stdlib.h>
#include "string.h"

int main(){
    size_t nChar;

    char * str = get_input(&nChar);
    modify_string(str, nChar);
    printf("Result: %s", str);

    free (str);
}