// Date_Class.cpp : This file contains the declarations of the Date class

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
using namespace std;

//Date class
//Stores a valid calendar date and provides utilities for
//validation, leap-year checks, last-day calculations, and
//multiple output formats.

class Date
{
private:
	int day;
	int month;
	int year;

	
	//Helper: Validates a full date (month/day/year).
	//Ensures month is 1–12, year is within allowed range,
	//and day does not exceed the last valid day of the month.
	
	bool isValidDate(int m, int d, int y) const;

public:

	
	//Constructor
	//Initializes the object to a valid date. If the provided
	//values are invalid, defaults to 1/1/1900.*/
	

	Date(int m = 1, int d = 1, int y = 1900);

	//Mutator
	//Sets the entire date at once. Falls back to default date
	//if any component is invalid.
	
	void setDate(int m, int d, int y);

	
	//Accessors
	//Return individual components of the stored date.
	
	int getmonth() const { return month; }
	int getday()   const { return day; }
	int getyear()  const { return year; }

	
	//Leap-year checks
	//isLeapYear() uses the stored year.
	//isLeapYear(int) checks any given year.
	
	bool isLeapYear() const;
	bool isLeapYear(int year) const;

	
	//Last-day calculations
	//lastDay() uses stored month/year.
	//lastDay(int,int) checks any month/year.
	
	int lastDay() const;
	int lastDay(int month, int year) const;

	
	//Formatting functions
	//Return the stored date in different string formats.
	
	string toNumeric() const;//MM/DD/YYYY
	string toLong()    const;//MonthName DD, YYYY
	string toEuro()    const;//DD/MM/YYYY
	
	//operator overloads

	//Prefix increment: ++d
	Date& operator++();

	//Postfix increment: d++
	Date operator++(int);

	//Prefix decrement: --d
	Date& operator--();

	//Postfix decrement: d--
	Date operator--(int);

	//Subtraction: returns the number of days between dates
	int operator-(const Date& other) const;

	//Stream insertion: cout << date
	friend ostream& operator<<(ostream& out, const Date& d);

	//Stream extraction: cin >> date
	friend istream& operator>>(istream& in, Date& d);
};

#endif


