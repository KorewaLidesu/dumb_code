/*
* 2023-2023, Korewa_Li, All rights reserved.
*/

#include <string>
#include <iostream>

class Letter {
	private:
		std::string title;
		std::string recipient;
		static int count;
	public:
		void setRecipient(std::string, std::string);
		void displayGreeting();
		static void displayCount();
};
int Letter::count = 0;

void Letter::setRecipient(std::string title, std::string recipient) {
	this -> title = title;
	this -> recipient = recipient;
	this -> count++;
}

void Letter::displayGreeting() {
	std::cout << "Dear " << title << ". " << recipient << ","       << std::endl
			  << "Thank you for your recent order. We look"         << std::endl 
		      << "forward to serve you again soon."                 << std::endl 
		      << "\t\tSincerely," << std::endl << "\t\tABC Company" << std::endl;
}

void Letter::displayCount() {
	std::cout << std::endl << "Current count is " << count << std::endl << std::endl;
}

int main() {
	bool loop = true;
	while (loop) {
		Letter letter;
		std::string title, recipient;
		std::cout << "Enter title for recipient, for example 'Mr' or 'Ms' >> ";
		std::cin >> title;
		std::cout << "Enter last name of recipient >> ";
		std::cin >> recipient;
		letter.setRecipient(title, recipient);
		letter.displayGreeting();
		letter.displayCount();
		char choice;
		do {
			std::cout << "Do you want to send another - y or n? ";
			std::cin >> choice;
			if (choice == 'N' || choice == 'n') { loop = false; break; }
			else if (choice != 'Y' and choice != 'y')
            	std::cout << choice << " is not a valid option. Try agian" << std::endl;
		} while (choice != 'Y' and choice != 'y');
	}	 
}
