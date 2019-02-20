// bin2Decimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int userInput = 0;
	int counter = 0;
	int result = 0;

	cout << "Enter a series of zeros and ones to covert to decimal." << endl;
	cin >> userInput;

	while (userInput >= 1)
	{
		if (userInput % 10 == 1)
			result += pow(2, counter);

		counter++;
		userInput /= 10;
	}

	cout << result << endl;

	if(1)

    return 0;
}

