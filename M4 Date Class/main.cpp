// M4 Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	cout << "===== DATE VLASS OPERATOR TESTS =====\n\n";

	//1. Test stream extraction (>>) and instertion (<<) operators
	Date userDate;
	cout << "Testing input operator >>\n";
	cin >> userDate;
	cout << "You entered: " << userDate << "\n\n";


	//2. Test prefix increment operator (++d)
	Date d1(12, 31, 2025);
	cout << "Starting date for prefix increment test: " << d1 << "\n";
	++d1;
	cout << "Results: " << d1 << "\n\n";

}