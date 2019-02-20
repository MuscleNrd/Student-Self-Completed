// ClassFraction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;


fraction::fraction(int a, int b)
{
	this->numberator = a;
	this->denominator = b;
}

int fraction::getNumerator()
{
	return this->numberator;
}

int fraction::getDenominator()
{
	return this->denominator;
}

void fraction::print()
{
	/*
	char numerator[40];
	char demoninator[40];
	char output[40];
	_itoa_s(this->getNumerator(), numerator, 10);
	_itoa_s(this->getDenominator(), demoninator, 10);

	strcpy_s(output, numerator);
	strcat_s(output, "/");
	strcat_s(output, demoninator);
	*/
	
	cout << this->getNumerator() << "/" << this->getDenominator() << endl;
}



int main(int argc, char* argv[])
{
	fraction f1(2, 5);

	f1.print();

	if (1)
	{
		
	}
}


