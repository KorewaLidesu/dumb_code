#include<iostream>
#include<string>
using namespace std;

template<class T>
T findLargest(T x, T y)
{
	T big;
	if(x > y)
		big = x;
	else
		big = y;
	return big;
}

class PhoneCall
{
    friend ostream& operator<<(ostream&, PhoneCall);
    private:
        int minutes;
    public:
        PhoneCall(int min = 0) : minutes(min) {}
        bool operator>(PhoneCall);
};

ostream& operator<<(ostream& out, PhoneCall call)
{
	out << "Phone call that lasted " <<
	call.minutes << " minutes" << endl;
	return out;
}

bool PhoneCall::operator>(PhoneCall call)
{
	bool isTrue = false;
	if(minutes > call.minutes)
		isTrue = true;
	return isTrue;
}

int main()
{
    int a;
    double b;
    PhoneCall oneCall(4);
    PhoneCall anotherCall(6);
    PhoneCall c(0);
    a = findLargest(3, 5);
    b = findLargest(12.3, 5.7);
    c = findLargest(oneCall, anotherCall);
    cout << "The largest ones are" << endl << a <<
    endl << b << endl << c << endl;
    return 0;
}
