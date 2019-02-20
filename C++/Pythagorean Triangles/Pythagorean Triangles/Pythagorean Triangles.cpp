// Pythagorean Triangles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int row;
	int column;
	int space =0;
	// first triangle
	for (int x = 1; x <= 10; x++)
	{
		for (int z = 1; z <= x; z++)
			cout << "*";
		cout << endl;
	}

	cout << endl;

	// second triangle

	for (int x = 10; x >= 1; x--)
	{
		for (int z = x; z >= 1; z--)
			cout << "*";
		cout << endl;
	}

	cout << endl;

	// third triangle

	for (int x = 10; x >= 1; x--)
	{
		if (space > 0)
		{
			for (int y = 1; space >= y; y++)
				cout << ' ';
		}

		for (int z = x; z >= 1; z--)
			cout << "*";
			
		space++;
		cout << endl;
	}

	cout << endl;

	// fourth triangle

	space = 9;
	for (int x = 10; x >= 1; x--)
	{
		for (int z = 1; z <= space; z++)
			cout << ' ';
		
		for (int y = x; y <= 10 ; y++)
		cout << "*";
		cout << endl;
		space--;
	}
		

	if (1)

    return 0;
}

