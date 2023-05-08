#include <iostream>
using namespace std;

//cho ma tran gom m dong n cot, tim max va min cua ma tran

//Input: Matrix of m row, n column (array)
//Output: Max, min within the matrix

int main() {
	int m, n; 
	cout<<"Kich thuoc ma tran: \nm = "; cin>>m; cout<<"n = "; cin>>n;
	//Should I just allow array with 1 element?
	if (m<2 && n<2) cout<<"Kich thuoc mang khong du lon de thuc hien so sanh.";
	else {
		int N[m][n];
		
		//This will allow Max to get first element of array, so no more first bool
		cout<<"N[1][1] = "; cin>>N[0][0];
		int Max = N[0][0] , Min = N[0][0];
		
		//As first element is use, this will run on first row
		for (int j = 1 ; j < n ; j++) {
			cout<<"N[1]["<<(j+1)<<"] = "; cin>>N[0][j];
			if (Max <= N[0][j]) Max = N[0][j];
			if (Min >= N[0][j]) Min = N[0][j];
		}
		
		//Input & Compare
		for (int i = 1 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				cout<<"N["<<(i+1)<<"]["<<(j+1)<<"] = "; cin>>N[i][j];
				if (Max <= N[i][j]) Max = N[i][j];
				if (Min >= N[i][j]) Min = N[i][j];
			}
		}
		
		cout<<"Max = "<<Max<<"\nMin = "<<Min;
	}
}
