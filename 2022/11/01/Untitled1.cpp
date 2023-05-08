#include <iostream>

int UCLN(int m, int n) {
	while (true) {
		if (m == n) return m;
		else if (m > n) m -= n;
		else n-= m;
	}
}

int main() {
	int m, n;
	std::cout<<"Nhap m, n: "; std::cin>>m>>n;
	std::cout<<"UCLN cua 2 so la: "<<UCLN(m, n);
}
