#include<iostream>
#include<string>
using namespace std;
int getPositiveSingleDigit()
{
    int userEntry;
    const int LOW = 0;
    const int HIGH = 9;
    const string ERROR_MSG = "Negative number";
    cout << "Enter a single-digit positive value ";
    cin >> userEntry;
    if(userEntry < LOW)
        throw(ERROR_MSG);
    if(userEntry > HIGH)
        throw(userEntry);
    return userEntry;
}

int main()
{
    int value;
    try
    {
    value = getPositiveSingleDigit();
    cout << "The entered value was good" << endl;
    }
    catch(string msg)
    {
        cout << "A message was thrown " << endl;
        cout << msg << endl;
    }
    catch(int badValue)
    {
    const int REDUCTION = 10;
    value = badValue % REDUCTION;
    cout << "A value was thrown " << endl;
    cout << "The number you entered, " << badValue << ", is too large." << endl;
    cout << "So it is being reduced to " << value << endl;
    }
    cout << "The value at the end of the program is " << value << endl;
    return 0;
}
