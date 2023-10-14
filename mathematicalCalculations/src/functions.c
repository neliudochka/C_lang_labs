#include<math.h>
#include "functions.h"

float calculateZ1(float L) {
    return (1 - 0.25*sin(2*L)*sin(2*L)+cos(2*L));
}

float calculateZ2(float L) {
    return cos(L)*cos(L)+cos(L)*cos(L)*cos(L)*cos(L);
}