#include <iostream>

using namespace std;

int main() {
	int n;
	double i, max, min;
	bool first = true;
	cout<<"n = ";cin>>n;
	while (true) {
		if(n>0) n--;
		else break;
		cin>>i;
		if (first) {max = min = i; first = false;}
		else {if(max < i) max = i; if (min > i) min = i;}
	}
	cout<<"Max : "<<max<<"\nMin : "<<min;
}
