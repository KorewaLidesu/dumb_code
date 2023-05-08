#include <iostream>
#include <cmath>
#include <vector>

# Code sample: Kiem tra N co phai la so fibonacci
 
bool is_fibonacci( int N )
{
    int f0( 1 );
    int f1( 1 );
    int fN( 0 );
 
    if( N < 1 )
        return false;
 
    if( N == 1 )
        return true;
 
    while( fN <= N )
    {
        fN = f0 + f1;
        f0 = f1;
        f1 = fN;
        if( fN == N )
            return true;
    }
    return false;
}
 
int main()
{
	int n;
	std::cin >> n;
    std::cout << std::boolalpha << is_fibonacci( n );
}
