//Date_Class.cpp : This file contains the implementation of the Date class
#include "Date.h"
#include <sstream>
#include <iostream>
#include <string>

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