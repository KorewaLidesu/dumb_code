// hugeint1.h
// Definition for Class HugeInt
#ifndef HUGEINT1_H
#define HUGEINT1_H

#include <iostream>
#include <cctype>
#include <stdio.h>
#include <string.h>
using std::ostream;

class HugeInt
{
    friend ostream &operator<<(ostream &, const HugeInt &);
    public:
        HugeInt(long = 0); // conversion/ default constructor
        HugeInt(const char *); // conversion constructor
        HugeInt operator+(const HugeInt &); // add another Hugelnt
        HugeInt operator+(int); // add an int
        HugeInt operator+(const char *); // add an int in a char *
        bool operator==(const HugeInt);
        bool operator!=(const HugeInt);
    private:
        int size = 30;
        short* integer;
};

// Printout value using stdout
ostream &operator<<(ostream &out, const HugeInt &input)
{
    bool isStart = false;
    for (int i = 0 ; i < input.size ; i++)
    {
        if (input.integer[i] != 0) isStart = true; 
        if (isStart) out << input.integer[i];
    }
    return out;
}

// HugeInt contructor with long parameter
HugeInt::HugeInt(long input)
{
    integer = new short[size];

    // Filling array with default value (0)
    for (int i = 0 ; i < 30 ; i++) 
        integer[i] = 0;

    // Inject value from input to the array
    for (int i = 29 ; i >= 0 ; i++)
    {
        if (input != 0)
        {
            integer[i] = input % 10;
            input /= 10;
        } else return;
    }
}

// HugeInt contructor with char parameter
HugeInt::HugeInt(const char *string)
{
    // Filling array with default value (0)
    for (int i = 0; i <= 29; i++)
    {
        integer[i] = 0;
    }

    // Get string leghth via external library
    int stringLength = strlen(string);

    // Inject value from input to the array
    for (int i = 30 - stringLength, j = 0; i <= 29; i++, j++ )
    {
        if (isdigit (string[j]))
            integer[i] = string[j] - '0';
    }
}

// Operator plus with object parameter
HugeInt HugeInt::operator+(const HugeInt &addition)
{
    HugeInt temp;
    for (int i = 29 ; i >= 0 ; i++) {
        temp.integer[i] += this -> integer[i] + addition.integer[i];

        // if value within pointer is more than 9,
        // the next pointer will be increased to get correct value
        if (temp.integer[i] > 9 && i != 0)
        {
            temp.integer[i] -= 10;
            temp.integer[i - 1] += 1;
        }
    }
    return temp;
}

// Operator plus with integer parameter
HugeInt HugeInt::operator+(int intInput)
{
    HugeInt temp;
    for (int i = 29 ; i >= 0 ; i++)
    {
        if (intInput == 0) break; // If intInput already at 0, we dont need to operate anymore
        temp.integer[i] += this -> integer[i] + intInput % 10;
        intInput /= 10;
        if (temp.integer[i] > 9 && i != 0)
        {
            temp.integer[i] -= 10;
            temp.integer[i - 1] += 1;
        }
    }
    return temp;
}

// Operator plus with string parameter
HugeInt HugeInt::operator+(const char *string)
{
    HugeInt temp;
    int stringLength = strlen ( string );

    for (int i = 30 - stringLength, j = 0; i <= 29; i++, j++ )
    {
        if (isdigit (string[j]))
            temp.integer[i] += this -> integer[i] + (string[j] - '0');
        if (temp.integer[i] > 9 && i != 0)
        {
            temp.integer[i] -= 10;
            temp.integer[i - 1] += 1;
        }
    }
    return temp;
}

bool HugeInt::operator==(const HugeInt val)
{
    if (size != val.size) return false;
    else
    {
        for (int i = 0 ; i < size ; i++)
        {
            if (integer[i] != val.integer[i]) 
            {
                return false;
            }
        }
    }
    return true;
}
bool HugeInt::operator!=(const HugeInt val)
{
    return !(*this == val);
}
#endif