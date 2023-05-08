#include <stdio.h>
#include <math.h>

void main() {
    int t = 16, y = 28;
    do {
        if (t < y) {
            t += y;
            y = t - y;
            t -= y;
        }
        t -= y;
    } while (t != y);
    printf("t = %d", t);
}