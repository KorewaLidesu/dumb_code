#include <iostream>
#include <string>
using namespace std;
int getUserNumber()
{
    int userEntry;
    cout << "Enter a positive value ";
    cin >> userEntry;
    if (userEntry < 0)
        exit(1);
    return userEntry;
}

int main ( )
{
    int returnedValue;
    returnedValue = getUserNumber();
    cout << "Data entry value is " <<
        returnedValue << endl;
    cout << "End of program" << endl;
    return 0;
}