#include <iostream>

template <class T, class U>
void displayAndCompare(T val1, U val2)
{
    std::cout << "First is " << val1 << " Second is " << val2 << " ";
    if (val1 > val2)
        std::cout << " First is larger" << std::endl;
    else if (val1 == val2)
        std::cout << " First and second are equal" << std::endl;
    else 
        std::cout << " Second is larger" << std::endl;
}

class PhoneCall
{
    friend std::ostream& operator<<(std::ostream&, PhoneCall);
    private:
        int minutes;
    public:
        PhoneCall(int min = 0) : minutes(min) {}
        bool operator>(PhoneCall);
        bool operator>(int);
        bool operator==(PhoneCall);
        bool operator==(int);
};

std::ostream& operator<<(std::ostream& out, PhoneCall call)
{
	out << "Phone call that lasted " <<
	call.minutes << " minutes" << std::endl;
	return out;
}

bool PhoneCall::operator>(PhoneCall call)
{
	bool isTrue = false;
	if(minutes > call.minutes)
		isTrue = true;
	return isTrue;
}

bool PhoneCall::operator>(int min)
{
	bool isTrue = false;
	if(minutes > min)
		isTrue = true;
	return isTrue;
}

bool PhoneCall::operator==(PhoneCall call)
{
	bool isTrue = false;
	if(minutes == call.minutes)
		isTrue = true;
	return isTrue;
}

bool PhoneCall::operator==(int min)
{
	bool isTrue = false;
	if(minutes == min)
		isTrue = true;
	return isTrue;
}

int main()
{
    int a = 68, b = 20;
    double c = 68.5;
    char d = 'D';
    PhoneCall oneCall(3), anotherCall (5);
    displayAndCompare(a, b);
    displayAndCompare(a, 68);
    displayAndCompare(a, c);
    displayAndCompare(a, d);
    displayAndCompare(c, d);
    displayAndCompare(oneCall, a);
    displayAndCompare(oneCall, 3);
    displayAndCompare(oneCall, anotherCall);
    displayAndCompare(oneCall, c);
    return 0;
}