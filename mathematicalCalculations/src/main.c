#include<stdio.h>
#include "functions.h"

void main() {
    float L = 0.0;
    
    printf("Enter L\n");
    scanf("%f", &L);
    float z1 = calculateZ1(L);
    float z2 = calculateZ2(L);
    printf("z1 = %f\n", z1);
    printf("z2 = %f\n", z2);
}
