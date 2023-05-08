#include "stdio.h"

// Code sample: Cho so nguyen duong n. Tim cac so nguyen to nho hon n.

using namespace std;

int main() {
	int n;
	cout<<"Nhap n = ";cin>>n;
	bool nto = true;
	for (int i = 2; i<n ; i++){
		for (int j = 2; j<i ; j++) if (i%j == 0) {nto = false; break;}
		if (!nto) {nto = true;continue;}
		cout<<i<<" ";
	}
}
