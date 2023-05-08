#include <stdio.h>
#include <math.h>

void main() {
    int M = 15, i = 2;
    while (i <= sqrt(M)) {
        if (M % i == 0) {
            printf("i = %d", i);
            return 0;
        } 
        i += 1;
    }
    printf("i = %d", M);
    return 1;
}