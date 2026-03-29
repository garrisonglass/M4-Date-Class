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
}

