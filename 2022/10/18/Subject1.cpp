#include <iostream>
using namespace std;

//cho 1 mang gom n phan tu nguyen, tim phan tu lon nhat va phan tu nho nhat

//Input: Array with n elements of int value
//Output: Max & Min within Array

int main() {
	int n; 
	cout<<"Kich thuoc mang: "; cin>>n;
	//Should I just allow array with 1 element?
	if (n<2) cout<<"Kich thuoc mang khong du lon de thuc hien so sanh.";
	else {
		int N[n];
		
		//This will allow Max to get first element of array, so no more first bool
		cout<<"N[0] = "; cin>>N[0];
		int Max = N[0] , Min = N[0];
		
		//Compare
		for (int i = 1 ; i < n ; i++) {
			cout<<"N["<<i<<"] = "; cin>>N[i];
			if (Max <= N[i]) Max = N[i];
			if (Min >= N[i]) Min = N[i];
		}
		cout<<"Max = "<<Max<<"\nMin = "<<Min;
	}
}
