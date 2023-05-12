#include<string>
#include<iostream>

class Name {
private:
	std::string first;
	std::string middle;
	std::string last;
public:
	Name(std::string, std::string, std::string);
	void displayFullName();
};

Name::Name(std::string first, std::string middle, std::string last) {
	this->first = first;
	this->middle = middle;
	this->last = last;
}

void Name::displayFullName() {
	std::cout << first << " " << middle << " " << last << std::endl;
}

class CreditData
{
private:
	double currentBalance;
	double maxBalance;
public:
	CreditData(double, double = 0);
	void displayCreditData();
};

CreditData::CreditData(double currBal, double maxBal)
{
	currentBalance = currBal;
	if (maxBal < currBal)
		maxBalance = currBal;
	else
		maxBalance = maxBal;
}

void CreditData::displayCreditData()
{
	double creditLeft = maxBalance - currentBalance;
	std::cout << "Current balance: $" << currentBalance <<
		"\nMaximum balance $" << maxBalance << "\nCredit left: $" <<
		creditLeft << std::endl;
}

class Customer {
private:
	Name name;
	CreditData credit;
	std::string phoneNumber;
public:
	Customer(std::string, std::string, std::string, double, double, std::string);
	void showCustomer();
};

Customer::Customer(std::string first, std::string middle, std::string last,
	double currentBal, double limitBal, std::string phoneNumber) : name(first, middle, last), credit(currentBal, limitBal)
{
	this->phoneNumber = phoneNumber;
}
void Customer::showCustomer() {
	name.displayFullName();
	credit.displayCreditData();
}

int main()
{
	int x;
	const int TIMES = 2;
	std::string first, middle, last, phone;
	double bal, lim;
	for (x = 0; x < TIMES; ++x)
	{
		std::cout << std::endl <<
			"Please enter first name for customer #" <<
			(x + 1) << " ";
		std::cin >> first;
		std::cout << "Please enter middle name ";
		std::cin >> middle;
		std::cout << "Please enter last name ";
		std::cin >> last;
		std::cout << "Enter current balance ";
		std::cin >> bal;
		std::cout << "Enter credit limit ";
		std::cin >> lim;
		std::cout << "Enter phone number ";
		std::cin >> phone;
		Customer cust(first, middle, last, bal, lim, phone);
		cust.showCustomer();
	}
}