#include <stdio.h>
#include <math.h>
#define saiso (1e-5) 

float pt(float a){
    return exp(a) - a*a*a;
}

void main() {
    float a,b,c;
    int trigger = 0;
    printf("Input [a,b]: "); scanf("%f%f", &a, &b);
    if (b<a) printf("Invalid input.");
    else {
        do {
            c = (a + b) / 2;
            if (pt(a)*pt(c) < 0) {b = c;}
            else if (pt(b)*pt(c) < 0) {a = c;}
        } while ((fabs(pt(c)) >= saiso));
        printf("Nghiem gan nhat cua phuong trinh: %f, %f", c, fabs(pt(c)) );
    }
}