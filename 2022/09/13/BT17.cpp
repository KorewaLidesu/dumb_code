#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	double sum = 0;
	cout<<"n = ";cin>>n;
	while(n>0) {
		sum = (double)sqrt(sum+2*n);
		n--;
	}
	cout<<sum;
}
