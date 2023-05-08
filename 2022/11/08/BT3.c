#include <stdio.h>

void main() {
    int a = 2, y = 4, T = 1;
    if(T < a * y ) {
        a = a * y * y;
        y = a * a * y * y;
    }
    if (T <= 3) T *= a;
    if (T <= 4) T *= y;
    if (T <= 16) T -= 10;
    printf("T = %d", T);
}