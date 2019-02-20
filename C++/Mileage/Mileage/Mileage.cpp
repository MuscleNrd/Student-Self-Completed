/*
Mileage.cpp : User types in a mileage and gallons expended over several iterations, output statistics.
Author: Steven Oseguera
Project 1: Question 1
10/6/2015
*/

#include "stdafx.h"
using namespace std;

int main()
{
	float miles				= 0;
	float totalMiles		= 0;
	float gallons			= 0;
	float totalGallons		= 0;
	float MPG				= 0;
	float totalMPG			= 0;

	while (miles != -1)
	{
		cout << "Please enter number of miles driven (-1 to quit): " << endl;
		cin >> miles;
		if (miles == -1)
			break;

		cout << "Please enter number of gallons used: " << endl;
		cin >> gallons;

		MPG = miles / gallons;

		totalMiles += miles;
		totalGallons += gallons;
		totalMPG = totalMiles / totalGallons;

		cout << "MPG: " << MPG << endl;
		cout << "Total MPG: " << totalMPG << endl;


	}


}

