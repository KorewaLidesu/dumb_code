#include <iostream>
#include <math.h>

# Code sample: Tim n so nguyen to

using namespace std;

int main() {
	int n;
	cout<<"Nhap n = ";cin>>n;
	bool nto = true;
	int i = 2;
	while (true){
		for (int j = 2; j<=(int)sqrt(i) ; j++) if (i%j == 0) {nto = false; break;}
		if (!nto) {nto = true;i++;continue;}
		else cout<<i<<" ";
		i++; n--;
		if (n == 0) break;
	}
}

