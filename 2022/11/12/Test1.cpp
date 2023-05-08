#include <iostream>
#include <Math.h>

int main() {
	int a = 1, b = 2, c = 1;
	std::cout<< "ax^2 + bx + c = 0";
	int delta = b * b - 4 * a * c;
	if (delta == 0) {
		std::cout<< "x = " << (-c/a); //((b - sqrt(delta))/2*a)
	}
}
