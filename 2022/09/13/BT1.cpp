#include <iostream>

# Code sample: Kiem tra tinh tang giam cua day

using namespace std;

int main() {
	int n;
	cout<<"Array's number: ";cin>>n;
	int arr[n]; int checker;
	for (int i = 0; i<n ; i++) {
		cout<<"arr["<<i<<"] = ";cin>>arr[i];
		if (i>0) if (arr[i] != arr [i-1]) checker = 1;
	}
	
	if (checker == 1) {
		for (int i = 1; i<n ; i++) {
			if (checker == 1) {if (arr[i-1] <= arr[i]) checker = 2;}
			else if (arr[i-1] > arr[i]) checker = 0;
		}
	}
	
	switch(checker) {
		default:
			cout<<"Khong co thu tu tang giam";
			break;
		case 1:
			cout<<"Day giam";
			break;
		case 2:
			cout<<"Day tang";
			break;
	}
}
