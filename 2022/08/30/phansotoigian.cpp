#include <iostream>

using namespace std;

int UCLN(int a, int b) {
    int c;
    while (a != b) {
        if (a>b) a = a - b;
        else b = b - a;
    }
    return a;
}

int main(){
    int M, N;
    cin>>M>>N;
    if (M == N) cout << "M/N = 1";
    else {
        int ucln = UCLN(M,N);
        M = M / ucln; 
        N = N / ucln; 
        cout<< "M/N = " <<M<<"/"<<N;
    }
}