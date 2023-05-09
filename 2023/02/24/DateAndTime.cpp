#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

class DateAndTime {
	friend std::istream& operator>>(std::istream&, DateAndTime&);
	friend std::ostream& operator<<(std::ostream&, DateAndTime);
	private:
		int month, day, year;
		int hour, minute, second;
		int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Boilerplate
	public:
		// constructor with default variable
		DateAndTime(int day = 1, int month = 1, int year = 1900, int hour = 0, int minute = 0, int second = 0) 
			: day(day), month(month), year(year), hour(hour), minute(minute), second(second) {}
		// Date
		void setDate(int month, int day, int year) // DMY or MDY instead?
			{
				this -> month = month;
				this -> day = day;
				this -> year = year;
			}
		void setMonth(int month) { this -> month = month;}
		void setDay(int day) { this -> day = day; }
		void setYear(int year) { this -> year = year; }
		int getMonth() { return month; }
		int getDay() { return day; }
		int getYear() { return year; }
		void nextDay();
		// Time
		void setTime(int hour, int minute, int second)
			{
				this -> hour = hour;
				this -> minute = minute;
				this -> second = second;
			}
		void setHour(int hour) { this -> hour = hour; }
		void setMinute(int minute) { this -> minute = minute; }
		void setSecond(int second) { this -> second = second; }
		int getHour() { return hour; }
		int getMinute() { return minute; }
		int getSecond() { return second; }
		// Utils and output
		void printStandard();
		void printMilitary();
		int monthDays() { return days_per_month[month - 1]; }
		void tick();
		bool leapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
		void validate();
};

void DateAndTime::nextDay() {
	if (day == DateAndTime::monthDays()) {
    	day = 1;
	    if (month == 12) {
	        month = 1;
	        year = year + 1;
	    }
        else month = month + 1;
    } else day = day + 1;
}

void DateAndTime::printStandard() {
	validate();
	std::cout << "Standard: "
			  << std::setw(2) << std::setfill('0') << day      << "-"
			  << std::setw(2) << std::setfill('0') << month    << "-"
			  << year                                          << " "
			  << std::setw(2) << std::setfill('0') << hour     << ":"
			  << std::setw(2) << std::setfill('0') << minute   << ":"
			  << std::setw(2) << std::setfill('0') << second   << std::endl;
}

void DateAndTime::printMilitary() {
	validate();
	int tempHour = hour;
	if (hour > 12) tempHour -= 12;
	else if (hour == 0) tempHour = 12;
	std::cout << "Militaty: "
			  << std::setw(2) << std::setfill('0') << day  	   << "-"
			  << std::setw(2) << std::setfill('0') << month	   << "-"
			  << year                                          << " "
			  << std::setw(2) << std::setfill('0') << tempHour << ":"
			  << std::setw(2) << std::setfill('0') << minute   << ":"
			  << std::setw(2) << std::setfill('0') << second;
	if (hour != 0 && tempHour != hour)
		std::cout << " P.M.";
	else
		std::cout << " A.M.";
	std::cout << std::endl;
}

void DateAndTime::tick()
{
   	if (second == 59) {
    	second = 0;
	    if (minute == 59) {
	        minute = 0;
	        if (hour == 23) {
	        	hour = 0;
	        	nextDay();
			} else hour = hour + 1;
	    } else minute = minute + 1;
    } else second = second + 1;
}

void DateAndTime::validate()
{
	if (leapYear()) 
		days_per_month[1] = 29;
	else
		days_per_month[1] = 28;
	if (year < 0)
		throw std::runtime_error("Invalid \"year\" input. Expect [0, ");
	if (month < 1 || month > 12)
		throw std::runtime_error("Invalid \"month\" input. Expect [1, 12]");
	if (day < 1 || day > days_per_month[month - 1])
		throw std::runtime_error("Invalid \"day\" input. Expect [1, " + std::to_string(days_per_month[month - 1]) + "]");
	if (hour < 0 || hour > 23)
		throw std::runtime_error("Invalid \"hour\" input. Expect [0, 23]");
	if (minute < 0 || minute > 59)
		throw std::runtime_error("Invalid \"minute\" input. Expect [0, 59]");
	if (second < 0 || second > 59)
		throw std::runtime_error("Invalid \"second\" input. Expect [0, 59]");
}

std::istream& operator>>(std::istream& in, DateAndTime& dat)
{
	std::cout << "Input day: "; in >> dat.day;
	std::cout << "Input month: "; in >> dat.month;
	std::cout << "Input year: "; in >> dat.year;
	std::cout << "Input hour: "; in >> dat.hour;
	std::cout << "Input minute: "; in >> dat.minute;
	std::cout << "Input second: "; in >> dat.second;
	dat.validate();
	return in;
}

std::ostream& operator<<(std::ostream& out, DateAndTime dat)
{ // 24hours format output
	dat.printStandard();
	return out;
}


int main()
{
	DateAndTime dat;
	// std::cin >> dat;
	std::cout << dat;
	dat.printMilitary();
	dat.printStandard();
}