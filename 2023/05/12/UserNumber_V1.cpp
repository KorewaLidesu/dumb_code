#include <iostream>
#include <string>
using namespace std;
int getUserNumber()
{
    int userEntry;
    const string MSG = "Invalid entry";
    cout << "Enter a positive value ";
    cin >> userEntry;
    if (userEntry < 0)
        throw (MSG);
    return userEntry;
}

int main ( )
{
    int returnedValue;
    try
    {
        returnedValue = getUserNumber();
        cout << "Data entry value is " <<
            returnedValue << endl;
    }
    catch (const string message)
    {
        cout << "There was an error!" << endl;
        cout << message << endl;
    }
    cout << "End of program" << endl;
    return 0;
}