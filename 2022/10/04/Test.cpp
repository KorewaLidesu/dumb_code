#include<iostream>

using namespace std;

int getLength(int n) {
	int count = 0;
	while (n!=0) {
		count++; n /= 10;
	}
	return count;
}

void checker(int n, int lastdigit) {
	int N[length], i = 0;
	while (n!=0) {
		N[i] = n % 10;
		n /= 10; i++;
	}
	i = 0;
	while(lastdigit - i > 0) {
		if (N[i] != N[lastdigit-i]) {cout << "So da cho khong doi xung!"; return;}
		else {i++;}
	}
	cout << "So da cho doi xung!";
}

int main() {
	int n;
	cout<<"Nhap so nguyen duong n = "; cin>>n;
	int length = getLength(n);
	if (length < 2) { cout << "Khong the xet tinh doi xung do so da cho duoi 2 chu so!"; }
	else checker(n, length - 1);
}
