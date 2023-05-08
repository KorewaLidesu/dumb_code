#include <iostream>

using namespace std;

void ElectricBill(){
	int amount;
	cout<<"Luong dien tieu thu trong thang: "; cin>>amount;
	
	int base = amount / 100,extra = amount % 100;
		
	long total = 0;

	switch (base) {
				case 4:
			if (amount >= 401) {
				total += (amount - 400) * 2927;
				amount = 400;
			}
			total += (amount - 300) * 2834;
			amount = 300;
		case 3:
			if (extra != 0) {
				total += (amount - 300) * 2834;
				amount = 300;
			}
			total += (amount - 200) * 2536;
			amount = 200;
		case 2:
			if (extra != 0) {
				total += (amount - 200) * 2536;
				amount = 200;
			}
			total += (amount - 100) * 2014;
			amount = 100;
		case 1:
			if (extra != 0) {
				total += (amount - 100) * 2014;
				amount = 50;
			}
			total += (amount - 50) * 1734;
			amount = 50;
		default:
			if (amount > 50 && extra != 0) {
				total += (amount - 50) * 1734;
				amount = 50;
			}
			total += amount * 1678;
	}

	cout<< "Ban tra: " << total;
}

int main() {
	ElectricBill();
}
