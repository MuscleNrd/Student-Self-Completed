// GDC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int num1 = 0;
	int num2 = 0;
	int small = 0;

	cout << "Please enter 2 numbers: " << endl;

	cin >> num1 >> num2; // 12 6

		if (num1 == num2) // Same number? GCD must be itself.
		{
			cout << "GCD: " << num1 << endl;
			system("Pause");
			return 0;
		}

		if (num1 < num2) // Determine which number is smaller - for readability purposes ( redundant code )
			small = num1;
		else
			small = num2;

		for (int x = small; x >= 2; x--) // Loop through numbers 2 - "small", if both numbers are divisible by it, it's the GCD
		{
			if (num1 % x == 0 && num2 % x == 0) // is num1 and num2 BOTH divisible by x? If so, We found the GCD!
			{
				cout << "GCD: " << x << endl;
				system("Pause");
				return 0;
			}
		}

		// This means the above code didn't find any divisors from "small" - 2, therefore the numbers are prime, and the GCD is 1.
		cout << "GCD: 1" << endl;

		system("Pause");
		return 0;
}
