/*
* 2023-2023, Korewa_Li, All rights reserved.
*/
 
#include <iostream>
#include <iomanip>

class DateAndTime {
	private:
		int month;
		int day;
		int year;
		int hour;
		int minute;
		int second;
	public:
		DateAndTime(int = 1, int = 1, int = 1900, int = 0, int = 0, int = 0);
		void setDate(int, int, int);
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		int getMonth();
		int getDay();
		int getYear();
		void nextDay();
		void setTime(int, int, int);
		void setHour(int);
		void setMinute(int);
		void setSecond(int);
		int getHour();
		int getMinute();
		int getSecond();
		void printStandard();
		void printMilitary();
		int monthDays();
		void tick();
		bool leapYear();
};

DateAndTime::DateAndTime(int day, int month, int year, int hour, int minute, int second) {
	DateAndTime::day = day;
	DateAndTime::month = month;
	DateAndTime::year = year;
	DateAndTime::hour = hour;
	DateAndTime::minute = minute;
	DateAndTime::second = second;
};

void DateAndTime::setDate(int day, int month, int year) {
	if (year < 0) {
		std::cout << "Invalid \"year\" input. Expect >= 0" << std::endl;
		return;
	}
	if (month < 1 || month > 12) {
		std::cout << "Invalid \"month\" input. Expect 1 <-> 12" << std::endl;
		return;
	}
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (leapYear()) {
		days_per_month[1]++;
	}
	if (day < 1 || day > days_per_month[month - 1]) {
		std::cout << "Invalid \"day\" input. Expect 1 <-> " << days_per_month[month - 1] << std::endl;
		return;
	}
	DateAndTime::month = month;
	DateAndTime::day = day;
	DateAndTime::year = year;
}

void DateAndTime::setMonth(int month) {
	if (month < 1 || month > 12) {
		std::cout << "Invalid \"month\" input. Expect 1 <-> 12" << std::endl;
		return;
	}
	DateAndTime::month = month;
}

void DateAndTime::setDay(int day) {
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (leapYear()) {
		days_per_month[1]++;
	}
	if (day < 1 || day > days_per_month[month - 1]) {
		std::cout << "Invalid \"day\" input. Expect 1 <-> " << days_per_month[month - 1] << std::endl;
		return;
	}
	DateAndTime::day = day;
}

void DateAndTime::setYear(int year) {
	if (year < 0) {
		std::cout << "Invalid \"year\" input. Expect > 0" << std::endl;
		return;
	}
	DateAndTime::year = year;
}

int DateAndTime::getMonth() {
	return DateAndTime::month;
}

int DateAndTime::getDay() {
	return DateAndTime::day;
}

int DateAndTime::getYear() {
	return DateAndTime::year;
}

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

void DateAndTime::setTime(int hour, int minute, int second) {
	if (hour < 0 || hour > 23) {
		std::cout << "Invalid \"hour\" input. Expect 0 <-> 23"   << std::endl;
		return;
	}
	if (minute < 0 || minute > 59) {
		std::cout << "Invalid \"minute\" input. Expect 0 <-> 59" << std::endl;
		return;
	}
	if (second < 0 || second > 59) {
		std::cout << "Invalid \"second\" input. Expect 0 <-> 59" << std::endl;
		return;
	}
	DateAndTime::hour = hour;
	DateAndTime::minute = minute;
	DateAndTime::second = second;
}

void DateAndTime::setHour(int hour) {
	if (hour < 0 || hour > 23) {
		std::cout << "Invalid \"hour\" input. Expect 0 <-> 23"   << std::endl;
		return;
	}
	DateAndTime::hour = hour;
}

void DateAndTime::setMinute(int minute) {
	if (minute < 0 || minute > 59) {
		std::cout << "Invalid \"minute\" input. Expect 0 <-> 59" << std::endl;
		return;
	}
	DateAndTime::minute = minute;
}

void DateAndTime::setSecond(int second) {
	if (second < 0 || second > 59) {
		std::cout << "Invalid \"second\" input. Expect 0 <-> 59" << std::endl;
		return;
	}
	DateAndTime::second = second;
}

int DateAndTime::getHour() {
	return DateAndTime::hour;
}

int DateAndTime::getMinute() {
	return DateAndTime::minute;
}

int DateAndTime::getSecond() {
	return DateAndTime::second;
}

void DateAndTime::printStandard() {
	std::cout << "Standard: "
			  << std::setw(2) << std::setfill('0') << day      << "-"
			  << std::setw(2) << std::setfill('0') << month    << "-"
			  << year                                          << " "
			  << std::setw(2) << std::setfill('0') << hour     << ":"
			  << std::setw(2) << std::setfill('0') << minute   << ":"
			  << std::setw(2) << std::setfill('0') << second   << std::endl;
}

void DateAndTime::printMilitary() {
	int tempHour = hour;
	bool isPM = false;
	if (tempHour > 11) { isPM = true; tempHour -= 12;}
	if (tempHour == 0) tempHour = 12;
	std::cout << "Militaty: "
			  << std::setw(2) << std::setfill('0') << day  	   << "-"
			  << std::setw(2) << std::setfill('0') << month	   << "-"
			  << year                                          << " "
			  << std::setw(2) << std::setfill('0') << tempHour << ":"
			  << std::setw(2) << std::setfill('0') << minute   << ":"
			  << std::setw(2) << std::setfill('0') << second;
	if (isPM)
		std::cout << " P.M.";
	else
		std::cout << " A.M.";
	std::cout << std::endl;
}

int DateAndTime::monthDays() {
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (leapYear()) {
		days_per_month[1]++;
	}
	return days_per_month[month - 1];
}

void DateAndTime::tick() {
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

bool DateAndTime::leapYear() {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
