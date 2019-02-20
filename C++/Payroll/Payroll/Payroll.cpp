// Payroll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int hours = 0;
	double salary = 0;

	double payRate = 0;

	while(hours != -1)
	{
		cout << "Enter hours worked: (-1 to end)" << endl;
		scanf_s("%d", &hours);

		if (hours == -1)
			break;

		cout << "Enter hourly rate of the worker ($00.00): " << endl;
		scanf_s("%lf", &payRate);

		if (hours > 40)
		{
			int hoursOvertime = hours % 40;
			int overtimePay = hoursOvertime * payRate * 1.50;
			salary = (hours - hoursOvertime) * payRate + overtimePay;
		}
		else 
			salary = hours * payRate;

		cout << "Salary is: " << "$" << fixed << setprecision(2) << salary << endl;
	}


    return 0;
}

