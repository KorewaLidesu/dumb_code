#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
	short A[100][100];
  	int pos1, pos2;

  	/* initialize random seed: */
  	srand (time(NULL));
  
  	for (int i = 0; i <100; i++) {
  		for (int j = 0; j <100; j++){
	  		A[i][j] = rand() % 2;
		}
  	}
  	while (true) {
  			  		if (A[i][j] == 0) {
	  			if (rand() % 2 == 0) {
	  				pos1 = i; pos2 = j;
				}
			}
	  }
  	cout<<pos1<<"\|"<<pos2;
  	
}
