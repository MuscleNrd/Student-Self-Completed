#include "stdafx.h"

using namespace std;















TestClass::TestClass(int a, int b)
{
	this->number = a;
	this->number2 = b;
}

TestClass::TestClass()
{
	this->number = 0;
	this->number2 = 0;
}


int TestClass::getNumber1()
{
	return this->number;
}

int TestClass::getNumber2()
{
	return this->number;
}

TestClass operator+(const TestClass& lhs, const TestClass& rhs)
{
	TestClass temp;
	temp.number = lhs.number + rhs.number;
	temp.number2 = lhs.number2 + rhs.number2;

	return temp;
}

std::ostream& operator <<(std::ostream& out, TestClass& rhs)
{
	out << rhs.number << " - " << rhs.number2;
	return out;
}

std::istream& operator >>(std::istream& input, TestClass& rhs)
{
	input >> rhs.number;
	input >> rhs.number2;

	return input;
}