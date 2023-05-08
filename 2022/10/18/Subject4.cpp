#include <iostream>
using namespace std;

//cho 2 ma tran a[mxn] b[nxk], tinh tich 2 ma tran

//Input: 2 matrixs: A[m,n], B[n,k]
//Output: Multiplier of A and B

int main() {
	int m, n, k; 
	cout<<"m = "; cin>>m; cout<<"n = "; cin>>n; cout<<"k = "; cin>>k;
	if (m<2 && n<2 && k<2) cout<<"Kich thuoc mang khong du lon de thuc hien so sanh.";
	else {
		int A[m][n], B[n][k];
		
		//A[m][n]
		for (int a = 0 ; a < m ; a++) {
			for (int b = 0 ; b < n ; b++) {
				cout<<"A["<<(a+1)<<"]["<<(b+1)<<"] = "; cin>>A[a][b];
			}
		}
		
		//B[n][k]
		for (int a = 0 ; a < n ; a++) {
			for (int b = 0 ; b < k ; b++) {
				cout<<"B["<<(a+1)<<"]["<<(b+1)<<"] = "; cin>>B[a][b];
			}
		}
		
		//Multiplier
		int C[m][k];
		for (int a = 0 ; a < m ; a++) {
			for (int b = 0 ; b < k ; b++) {
				C[a][b] = 0;
				for(int c = 0 ; c < n ; c++) {
					C[a][b] += A[a][c] * B[c][b];
				}
			}
		}
		
		//Output result
		for (int a = 0 ; a < m ; a++) {
			for (int b = 0 ; b < k ; b++) {
				cout<<"C["<<(a+1)<<"]["<<(b+1)<<"] = "<<C[a][b]<<endl;
			}
		}
	}
}
