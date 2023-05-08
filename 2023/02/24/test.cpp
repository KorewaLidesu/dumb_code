#include<iostream>
#include<windows.h>

using namespace std;

class DateAndTime
{
	private:
		int day;
		int month;
		int year;
		int second;
		int minute;
		int hour;
	public:
		DateAndTime(int =1, int =1, int =1900
					,int =0, int =0, int =0);
		void setDate(int,int,int);
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		int getDay(void);
		int getMonth(void);
		int getYear(void);
		void nextDay();
		void nextMonth();
		void setClock(int,int,int);
		void setSecond(int);
		void setMinute(int);
		void setHour(int);
		int getSecond();
		int getMinute();
		int getHour();
		void nextSecond();
		void nextMinute();
		void nextHour();
};
DateAndTime::DateAndTime(int dd, int mm, int yyyy
					,int h, int m, int s)
{
	this->day = dd;
	this->month = mm;
	this->year = yyyy;
	this->hour=h;
	this->minute=m;
	this->second=s;
}

void DateAndTime::setDate(int dd,int mm, int yyyy)
{
	DateAndTime::setDay(dd);
	DateAndTime::setMonth(mm);
	DateAndTime::setYear(yyyy);
}

void DateAndTime::setDay(int dd)
{
	cout<<"Nhap ngay:";
	cin >>dd;
	DateAndTime::day = dd;
}

void DateAndTime::setMonth(int mm)
{
	cout<<"Nhap thang:";
	cin >>mm;
	DateAndTime::month = mm;
}

void DateAndTime::setYear(int yyyy)
{
	cout<<"Nhap nam:";
	cin >>yyyy;
	DateAndTime::year = yyyy;
}

int DateAndTime::getDay()
{
	return DateAndTime::day;
}

int DateAndTime::getMonth()
{
	return DateAndTime::month;
}

int DateAndTime::getYear()
{
	return DateAndTime::year;
}

void DateAndTime::nextMonth()
{
	if(DateAndTime::month<12)
	{
		DateAndTime::month +=1;
	}
	if(DateAndTime::month==12)
	{
		DateAndTime::month=1;
		DateAndTime::year +=1;
	}
}


void DateAndTime::nextDay()
{
	switch(this->month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			{
				if(DateAndTime::day<31)
					DateAndTime::day +=1;
				if(DateAndTime::day==31)
				{
					DateAndTime::day = 1;
					DateAndTime::nextMonth();
				}
				break;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			{	if(DateAndTime::day<=29)
					DateAndTime::day +=1;
				if(DateAndTime::day==30)
				{	
					DateAndTime::nextMonth();
					this->day = 1;	
				}
				
				break;
			}
		case 2:
			{
				if(DateAndTime::day<28)
					DateAndTime::day+=1;
				if(DateAndTime::day==28)
					{
						DateAndTime::day=1;
						DateAndTime::nextMonth();
					}
				break;
			}
	}
}

void DateAndTime::setClock(int h,int m ,int s)
{
	DateAndTime::setHour(h);
	DateAndTime::setMinute(m);
	DateAndTime::setSecond(s);
}
void DateAndTime::setSecond(int s)
{	
	cout<<"Nhap giay:";
	cin >>s;
	this->second=s;
}
void DateAndTime::setMinute(int m)
{
	cout<<"Nhap phut:";
	cin >>m;
	this->minute=m;
}
void DateAndTime::setHour(int h)
{
	cout<<"Nhap gio:";
	cin >>h;
	this->hour=h;
}

int DateAndTime::getSecond()
{
	return this->second;
}
int DateAndTime::getMinute()
{
	return this->minute;
}
int DateAndTime::getHour()
{
	return this->hour;
}

void DateAndTime::nextHour()
{
	if(this->hour<23)
		hour +=1;
	if(this->hour==23)
	{
		hour =0;
		this->nextDay();
	}
}

void DateAndTime::nextMinute()
{
	if(this->minute<59)
		minute +=1;
	if(this->minute==59)
	{
		minute = 0;
		this->nextHour();
	}
}

void DateAndTime::nextSecond()
{
	if(this->second<59)
		second +=1;
	if(this->second==59)
	{
		second = 0;
		this->nextMinute();
	}
}

int main()
{
	int x;
	int dd,mm,yyyy,h,m,s;
	DateAndTime dt(dd,mm,yyyy,h,m,s);
	do
	{
		cout<<"_____________________"<<endl;
		cout<<"1.Cai dat ngay thang."<<endl;
		cout<<"2.Cai dat thoi gian."<<endl;
		cout<<"3.In ra thoi diem."<<endl;
		cout<<"4.Tang them 1 ngay."<<endl;
		cout<<"5.Tang them 1 giay."<<endl;
		cout<<"0.Thoat chuong trinh."<<endl;
		cout<<"_____________________"<<endl;
		cout<<"Nhap lua chon:"; cin>>x;
		switch(x)
		{	
			case 1:
				dt.setDate(dd,mm,yyyy);
				break;
			case 2:
				dt.setClock(h,m,s);
				break;
			case 3:
				system("cls");
				cout<<"Ngay "<<dt.getDay()<<"/"<<dt.getMonth()<<"/"<<dt.getYear()<<endl;
				cout<<dt.getHour()<<":"<<dt.getMinute()<<":"<<dt.getSecond()<<endl;
				break;
			case 4:
				dt.nextDay();
				break;
			case 5:
				dt.nextSecond();
				break;
		}

	}
	while(x!=0);
}
