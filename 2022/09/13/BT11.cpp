#include <iostream>

using namespace std;

int main() {
	int n, tich=1;
	double sum=0;
	cout<<"i = ";cin>>n;
	for(int i = 1 ; i<=n ; i++) {
		tich *= i;
		sum += (double)1/tich;
	}
	cout<<sum;
}
