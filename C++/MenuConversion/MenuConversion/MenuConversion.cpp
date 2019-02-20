// MenuConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

// The input variable will be double because I want percision, since we are dealing with precise amounts. 
// Otherwise integer multiplication or division would truncate the decimal.

double milesToKilometer(double miles) { return  miles / 0.62137; }

double feetToMeter(double feet) { return feet / 3.2808; };

double farenheightToCelcius(double fahrenheit) { return ((fahrenheit - 32) * 5) / 9.0; };

int main()
{
	int option = 0;
	double input = 0;

	while (option != -1)
	{
		cout << endl;
		cout << "Welcome, please select from the following menu: -1 to exit" << endl;
		cout << setw(5) << "1. Miles -> Kilometers" << endl;
		cout << setw(5) << "2. Feet -> Meters" << endl;
		cout << setw(5) << "3. Fahrenheit -> Celsius" << endl;

		scanf_s("%d", &option);

		switch (option)
		{
			case 1:
			{
				cout << "Enter the amount of Miles" << endl;
				scanf_s("%lf", &input);
				cout << input << " Miles is " << milesToKilometer(input) << " Kilometers" << endl;
				break;
			}
			case 2:
			{
				cout << "Enter amount of Feet" << endl;
				scanf_s("%lf", &input);
				cout << input << " Feet is " << feetToMeter(input) << " Meters" << endl;
				break;
			}
			case 3:
			{
				cout << "Enter amount of Fahrenheit" << endl;
				scanf_s("%lf", &input);
				cout << input << " Fahrenheit is " << farenheightToCelcius(input) << " Celcius" << endl;
				break;
			}
			default:
				break;
		}
	}

	system("Pause");

	if (1)
    return 0;
}