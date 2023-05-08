#include <iostream>

# Code sample: Tim so lon nhat cua day

using namespace std;

int main() {
	int n, max;
	bool first = true;
	while (true) {
		cin>>n; if (n<0) break;
		if (first) {max = n; first = false;}
		else if(max < n) max = n;
	}
	cout<<max;
}
