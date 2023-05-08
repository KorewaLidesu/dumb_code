#include <iostream>
#include <cstring>
#include "hugeint1.h"

using namespace std;

class Array
{
	private:
		int size;
		HugeInt* temp;
	public:
		Array() : size(8) , temp(new HugeInt[size]) {} //default constructor with size of 8
		Array(const int size) : size(size), temp(new HugeInt[size]) {} // Array with custom size
		Array(const Array&); // copy array
		~Array() { delete[] temp; } // deconstructor
		Array& operator=(const Array&); // =
		bool operator==(const Array&) const; // ==
		bool operator!=(const Array&) const; // !=
		int getSize() const; // Size getter
};

Array::Array(const Array& original) : size(original.size), temp(new HugeInt[size])
{
	for (int i = 0; i < size; i++)
	{
		temp[i] = original.temp[i];
	}
}

Array& Array::operator=(const Array& array)
{
	if (this != &array)
	{
		delete[] temp;
		size = array.size;
		temp = new HugeInt[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = array.temp[i];
		}
	}
	return *this;
}

bool Array::operator==(const Array& third) const
{
	if (size != third.size)
	{
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		if (temp[i] != third.temp[i])
		{
			return false;
		}
	}
	return true;
}

bool Array::operator!=(const Array& fourth) const
{
	return !(*this == fourth);
}

int Array::getSize() const
{
	return size;
}

int main()
{
	Array arr1;
	Array arr2(43543);
	Array arr3(arr2);
	Array arr4(3464646);

	cout << "Array size: " << arr3.getSize() << endl;

	arr1 = arr2;
	if (arr1 == arr2) {
		cout << "arr1 bang arr2" << endl;
	} else { cout<<"arr1 khong bang arr2";}
	if (arr4 == arr2) {
		cout << "arr2 bang arr4" << endl;
	} else { cout<<"arr2 khong bang arr4";}

	return 0;
}
