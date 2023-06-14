// Li
// 2023 - 06 - 13

// Prevent conflict with other implementations
#ifndef LI_TIME
#define LI_TIME

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

class Time {
	friend std::istream& operator>>(std::istream&, Time&);
	friend std::ostream& operator<<(std::ostream&, Time&);
	private:
		int hour, minute, second;
	public:
		// constructor with default variable
		Time(int = 0, int = 0, int = 0);
		// Operator
		int operator-(Time&);
		// Time
		void setTime(int, int, int);
		void setHour(int);
		void setMinute(int);
		void setSecond(int);
		const int getHour();
		const int getMinute();
		const int getSecond();
		// Utils and output
		const int asSecond();
		void printStandard();
		void tick();
		void validate();
};

// Constructor
Time::Time(int hour, int minute, int second)
	: hour(hour), minute(minute), second(second)
{
}

int Time::operator-(Time& sub)
{
	return this -> asSecond() - sub.asSecond();
}

// Getter / Setter for Time
void Time::setTime(int hour, int minute, int second)
{
	this -> hour = hour;
	this -> minute = minute;
	this -> second = second;
}

void Time::setHour(int hour)
{
	this -> hour = hour;
}

void Time::setMinute(int minute)
{
	this -> minute = minute;
}

void Time::setSecond(int second)
{
	this -> second = second;
}

const int Time::getHour()
{
	return hour;
}

const int Time::getMinute()
{
	return minute;
}

const int Time::getSecond()
{
	return second;
}

void Time::printStandard() {
	validate();
	std::cout << std::setw(2) << std::setfill('0') << hour     << ":"
			  << std::setw(2) << std::setfill('0') << minute   << ":"
			  << std::setw(2) << std::setfill('0') << second   << std::endl;
}

void Time::tick()
{
   	if (second == 59) {
    	second = 0;
	    if (minute == 59) {
	        minute = 0;
	        if (hour == 23) {
	        	hour = 0;
			} else hour = hour + 1;
	    } else minute = minute + 1;
    } else second = second + 1;
}

void Time::validate()
{
	if (hour < 0 || hour > 23)
		throw std::runtime_error("Invalid \"hour\" input. Expect [0, 23]");
	if (minute < 0 || minute > 59)
		throw std::runtime_error("Invalid \"minute\" input. Expect [0, 59]");
	if (second < 0 || second > 59)
		throw std::runtime_error("Invalid \"second\" input. Expect [0, 59]");
}

const int Time::asSecond()
{
	return hour * 3600 + minute * 60 + second;
}

std::istream& operator>>(std::istream& in, Time& dat)
{
	std::cout << "+ Input hour: "; in >> dat.hour;
	std::cout << "+ Input minute: "; in >> dat.minute;
	std::cout << "+ Input second: "; in >> dat.second;
	dat.validate();
	return in;
}

std::ostream& operator<<(std::ostream& out, Time& dat)
{ // 24hours format output
	dat.printStandard();
	return out;
}

#endif