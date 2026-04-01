//M4 Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	cout << "===== DATE CLASS OPERATOR TESTS =====\n\n";

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

	//3. Test postfix increment operator (d++)
	Date d2(3, 14, 2024);
	cout << "Starting date for postfix increment test: " << d2 << "\n";	
	cout << "Applying d2++\n";
	Date d2_post = d2++;
	cout << "Returned (post) value: " << d2_post << "\n";
	cout << "New stored value: " << d2 << "\n\n";

	//4. Test prefix decrement operator (--d)
	Date d3(1, 1, 2025);
	cout << "Starting date for prefix decrement test: " << d3 << "\n";
	cout << "Applying --d3\n";
	--d3;
	cout << "Results: " << d3 << "\n\n";

	//5 . Test postfix decrement operator (d--) with leap year
	Date d4(3, 1, 2024);
	cout << "Starting date for postfix decrement test: " << d4 << "\n";
	cout << "Applying d4--\n";
	Date d4_post = d4--;
	cout << "Returned (post) value: " << d4_post << "\n";
	cout << "New stored value: " << d4 << "\n\n";

	//6 . Test postfix decrement operator (d--) without leap year
	Date d5(3, 1, 2025);
	cout << "Starting date for postfix decrement test: " << d5 << "\n";
	cout << "Applying d5--\n";
	Date d5_post = d5--;
	cout << "Returned (post) value: " << d5_post << "\n";
	cout << "New stored value: " << d5 << "\n\n";

	//7. Test subtraction operator (d1 - d2)
	Date a(10, 20, 1986);
	Date b(6, 8, 1986);
	cout << "Testing subtraction operator -\n";
	cout << a << " - " << b << " = " << (a - b) << " days\n\n";
	cout << "Testing reverse order\n";
	cout << b << " - " << a << " = " << (b - a) << " days\n\n";
	

	Date e(1, 1, 2000);
	Date f(1, 1, 2000);
	cout << "Testing same date (Y2K)\n";
	cout << e << " - " << f << " = " << (e - f) << " days\n";
	
	cout << "\n===== END OF OPERATOR TESTS =====\n";
	return 0;
}