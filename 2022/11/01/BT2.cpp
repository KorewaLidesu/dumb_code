#include <iostream>

void KTNT(int N) {
	for (int i = 2 ; i < N ; i++) {
		if (N % i == 0) {
			std::cout<<"N da cho khong la so nguyen so";
			return;
		}
	}
	std::cout<<"N da cho la so nguyen so";
}

int main() {
	int N;
	std::cout<<"Nhap N: "; std::cin>>N;
	if (N<2) {
		std::cout<<"N da cho khong la so nguyen so";
		return 0;
	}
	KTNT(N);
}
