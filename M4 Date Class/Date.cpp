//Date.cpp : This file contains the implementation of the Date class
#include "Date.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


//Constructor
//Stores a valid date or defaults to 1/1/1900 if invalid.

Date::Date(int m, int d, int y)
{
	if (isValidDate(m, d, y))
	{
		month = m;
		day = d;
		year = y;
	}
	else
	{
		month = 1;
		day = 1;
		year = 1900;
	}
}


//setDate
//Updates the stored date. If invalid, resets to default date.

void Date::setDate(int m, int d, int y)
{
	if (isValidDate(m, d, y))
	{
		month = m;
		day = d;
		year = y;
	}
	else
	{
		month = 1;
		day = 1;
		year = 1900;
	}
}


//isLeapYear (stored year)
//Delegates to the overloaded version.

bool Date::isLeapYear() const
{
	return isLeapYear(year);
}


//isLeapYear (given year)
//Implements the Gregorian leap-year rules:
//- divisible by 4 - leap year
//- except divisible by 100 - not leap
//- except divisible by 400 - leap

bool Date::isLeapYear(int year) const
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//lastDay (stored month/year)
//Returns the last valid day for the stored month/year.

int Date::lastDay() const
{
	return lastDay(month, year);
}


//lastDay (given month/year)
//Handles 30-day months, 31-day months, and February with
//leap-year logic.

int Date::lastDay(int m, int y) const
{
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m == 2)
	{
		if (isLeapYear(y))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else
	{
		return 31;
	}
}


//isValidDate
//Ensures year is within allowed range, month is 1–12, and
//day does not exceed the last valid day for that month/year.

bool Date::isValidDate(int m, int d, int y) const
{
	if (y < 1900 || y>2100)
	{
		return  false;
	}
	if (m < 1 || m > 12)
	{
		return false;
	}
	int maxDay = lastDay(m, y);
	if (d < 1 || d > maxDay)
	{
		return false;
	}
	return true;
}


//toNumeric
//Returns date in MM/DD/YYYY format.

string Date::toNumeric() const
{
	ostringstream print;
	print << month << "/" << day << "/" << year;
	return print.str();
}

//toLong
//Returns date in "MonthName DD, YYYY" format.

string Date::toLong() const
{
	static const string month_by_Name[] =
	{
		"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};
	ostringstream out;
	out << month_by_Name[month - 1] << " " << day << ", " << year;
	return out.str();
}


//toEuro
//Returns date in DD/MM/YYYY format.

string Date::toEuro() const
{
	static const string month_by_Name[] =
	{
		"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};
	ostringstream print;
	print << day << "/" << month << "/" << year;
	return print.str();
}

//Prefix increment operator (++d)
Date& Date::operator++()
{
	day++;

	if (day > lastDay(month, year))
	{
		day = 1;
		month++;

		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	return *this;
}

//Postfix increment operator (d++)
Date Date::operator++(int)
{
	Date temp = *this;//Save old value
	++(*this);        //Reuse prefix logic
	return temp;      //Return old value
}

//Prefix decrement operator (--d)
Date& Date::operator--()
{
	day--;

	if (day < 1)
	{
		month--;

		if (month < 1)
		{
			month = 12;
			year--;
		}

		day = lastDay(month, year);
	}
	return *this;
}

//Postfix decrement operator (d--)
Date Date::operator--(int)
{
	Date temp = *this;//Save old value
	--(*this);        //Reuse prefix logic
	return temp;      //Return old value
}

//Helper converts date to absolute day count
static int dateToDays(const Date& d)
{
	int m = d.getmonth();
	int y = d.getyear();

	int totalDays = y * 365 + (y / 4) - (y / 100) + (y / 400);

	static const int days_by_month[] = 
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 1; i < m; i++)
	{
		totalDays += days_by_month[i];
	}
	if (m > 2 && d.isLeapYear())
	{
		totalDays++;
	}

	totalDays += d.getday();

	return totalDays;
}

//subtraction operator (d1 - d2)
//Returns the number of days between dates.
int Date::operator-(const Date& other) const
{
	int d1 = dateToDays(*this);
	int d2 = dateToDays(other);
	return abs(d1 - d2);//elapsed days
}

//Stream insertion operator (cout << d)

ostream& operator<<(ostream& out, const Date& d)
{
	static const string month_by_Name[] =
	{
		"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};
	out << month_by_Name[d.getmonth() - 1] 
		<< " "  << d.getday() 
		<< ", " << d.getyear();
	return out;
}

//Stream extraction operator (cin >> d)
istream& operator>>(istream& in, Date& d)
{
	int m, day, y;
	char slash1, slash2;

	cout << "Enter date (MM/DD/YYYY): ";

	if (!(in >> m >> slash1 >> day >> slash2 >> y))
	{
		in.clear();//Reset error state
		in.ignore(numeric_limits<streamsize>::max(), '\n');//Discard bad input
		d.setDate(1, 1, 1900);//Default date
		return in;
	} 
	if (slash1 == '/' && slash2 == '/' && d.isValidDate(m, day, y))
	{
		d.setDate(m, day, y);
	}
	else
	{
		d.setDate(1, 1, 1900);//Default date
	}
	return in;	
}

//lecture 4/19/26 stop at 1:05
