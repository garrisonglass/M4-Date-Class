// M4 Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	cout << "===== DATE VLASS OPERATOR TESTS =====\n\n";

	//1. Test stream extraction (>>) and instertion (<<) operators
	//Date userDate;
	//cout << "Testing input operator >>\n";
	//cin >> userDate;
	//cout << "You entered: " << userDate << "\n\n";


	//2. Test prefix increment operator (++d)
	Date d1(12, 31, 2025);
	cout << "Starting date for prefix increment test: " << d1 << "\n";
	++d1;
	cout << "Results: " << d1 << "\n\n";

	//3. Test postfix increment operator (d++)
	Date d2(3, 14, 2024);
	cout << "Starting date for postfix increment test: " << d2 << "\n";	
	cout << "Applying d2++\n";
	Date d2_post = d2++;
	cout << "Returned (post) value: " << d2_post << "\n";
	cout << "New stored value: " << d2 << "\n";

	//4. Test prefix decrement operator (--d)
	Date d3(1, 1, 2025);
	cout << "\nStarting date for prefix decrement test: " << d3 << "\n";
	cout << "Applying --d3\n";
	--d3;
	cout << "Results: " << d3 << "\n\n";

}