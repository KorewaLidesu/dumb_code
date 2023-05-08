#include <iostream>
using namespace std;

//cho 1 mang gom n ptu nguyen, nhap vao 1 so x va dem so lan x xuat hien

//Input: Array of n int elements, a "x" number
//Output: Amount of times that "x" present

int main() {
	int n; 
	cout<<"n = "; cin>>n;
	if (n<2) cout<<"Kich thuoc mang khong du lon de thuc hien so sanh.";
	else {
		int N[n];
		//Array
		for (int i = 0 ; i < n ; i++) {
			cout<<"N["<<i<<"] = "; cin>>N[i];
		}
		int x, count = 0;
		cout<<"x = "; cin>>x;
		//Check of x
		for (int i = 0 ; i < n ; i++) {
			if (N[i] == x) count++;
		}
		cout<<"\"x\" presents "<<count<<" times.";
	}
}
