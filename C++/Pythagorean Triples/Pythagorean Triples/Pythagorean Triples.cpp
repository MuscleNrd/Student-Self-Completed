// Pythagorean Triples.cpp : Display to the screen every pythagorean combination up to 500.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	const int Triples = 500;   // Up to what number did you want to find Pythagorean Triples?
	bool outputToFile = true; // If this is true, wherever you compile this, it will make a .txt called "Triples" and put all the results in the text file =]


	ofstream myfile;
	if (outputToFile)
	{
		myfile.open("Triples.txt");
		myfile << "----------- All Pythagorean Triples Up To " << Triples << "-----------" << endl;
	}


	// We want to loop over 500 times. Where we only increment a2 and b2 and compare that value to an incrementing c2.

	// This will be our c squared. Since we are looking for values of the already squared c, it will be numbers from 1- 500, ergo, ran 500 times.
	for (int c = 1; c <= Triples; c++)
	{
		// This will be our first variable, "a", this will be squared, and compared to b.
		for (int a = 1, b = 1; a <= c; a++)
		{
			// The above loop starts the number a at 1. This loop will then go through all numbers 1 - 500 squared, compare it to 1 squared, and see if it's equal to c squared, which first run will be looking for all a^2 + b^2= 1
			// After this is compared to 'a', which is 1, 500 times, 'a' will then be incremented to 2, and we will repeat the process again, 500 times.
			for (int b = 1; b <= c; b++)
			{
				if (pow(a, 2) + pow(b, 2) == c)
				{
					cout << a << "^2" << " + " << b << "^2" << " = " << c << endl;
					if (outputToFile)
						myfile << a << "^2" << " + " << b << "^2" << " = " << c << endl;
				}
			}

			if (pow(a, 2) + pow(b, 2) == c)
			{
				cout << a << "^2" << " + " << b << "^2" << " = " << c << endl;
				if (outputToFile)
					myfile << a << "^2" << " + " << b << "^2" << " = " << c << endl;
			}
		}
	}
	if (outputToFile)
		myfile.close();
	return 0;
}

