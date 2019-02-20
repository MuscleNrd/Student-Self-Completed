// HUGEINT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

HugeInt::HugeInt(std::string Number)
{
	for (int x = 0; x < Number.size(); x++)
		this->Number.push_back(Number.at(x) - '0');
}

HugeInt::HugeInt()
{
	this->Number.clear();
}



HugeInt const &operator/(HugeInt &lhs, HugeInt &rhs)
{
	HugeInt temp("100");

	return temp;
}

HugeInt  operator-(HugeInt &lhs, HugeInt &rhs)
{
	HugeInt small;
	HugeInt large;
	HugeInt difference;

	if (lhs > rhs)
	{
		small = rhs;
		large = lhs;
	}
	else if (lhs < rhs)
	{
		small = lhs;
		large = rhs;
	}
	else
		return HugeInt(); // Numbers must be the same, so the result is 0;




	return difference;
}


bool const &operator <(HugeInt &lhs, HugeInt &rhs)
{
	//compare how many digits their are. if rhs has for then return true.
	if (lhs.Number.size() < rhs.Number.size())
		return true;
	else if (lhs.Number.size() > rhs.Number.size())
		return false;

	for (int i = 0; i < lhs.Number.size(); i++) {
		if (lhs.Number[i] < rhs.Number[i])
			return true;
		else if (lhs.Number[i] > rhs.Number[i])
			return false;
	}
	return false;
}



bool const &operator>(HugeInt &lhs, HugeInt &rhs)
{
	//compare how many digits their are. if lhs has for then return true.
	if (lhs.Number.size() > rhs.Number.size())
		return true;
	else if (lhs.Number.size() < rhs.Number.size())
		return false;

	for (int i = 0; i < lhs.Number.size(); i++) {
		if (lhs.Number[i] > rhs.Number[i])
			return true;
		else if (lhs.Number[i] < rhs.Number[i])
			return false;
	}
	return false;
}


bool const &operator==(HugeInt &lhs, HugeInt &rhs)
{
	//if diffrent in size then auto return false.
	if (lhs.Number.size() > rhs.Number.size())
		return false;
	if (lhs.Number.size() < rhs.Number.size())
		return false;

	//if any digit greater or lesser then return false.
	for (int i = 0; i < lhs.Number.size(); i++) {
		if (lhs.Number[i] > rhs.Number[i])
			return false;
		if (lhs.Number[i] < rhs.Number[i])
			return false;
	}
	//if false is never returned by the above 'if' then it must return true.
	return true;
}

// overloaded * operator
HugeInt  operator*(HugeInt &lhs, HugeInt &rhs)
{
	// declare object and variables
	HugeInt tempA;
	HugeInt tempB;

	// loop to insert integer into vector in reversed order
	// Modified to work with the multiplication specific only.  - Steve
	for (int i = 0; i < lhs.Number.size(); i++)
		tempA.Number.push_back(lhs.Number[lhs.Number.size() - (i + 1)]);

	for (int i = 0; i < rhs.Number.size(); i++)
		tempB.Number.push_back(rhs.Number[rhs.Number.size() - (i + 1)]);
	// End modification

	// Set new references for reversed vectors to be compatible with your multiplacation algorithm. - Steve

	lhs.Number = tempA.Number;
	rhs.Number = tempB.Number;

	HugeInt total;
	int multiple = 0;
	int temp = 0;

	for (int i = 0; i < rhs.Number.size(); i++)
	{
		for (int j = 0; j < lhs.Number.size(); j++)
		{
			multiple = lhs.Number[j] * rhs.Number[i];

			multiple += temp;
			temp = 0;

			while (multiple >= 10)
			{
				multiple -= 10;
				temp++;
			}

			if (i == 0)
				total.Number.push_back(multiple);
			else
			{
				if (j == lhs.Number.size() && temp != 0)
					total.Number.push_back(temp);
				else
				{
					total.Number[j + i] += multiple;
					if (total.Number[j + i] >= 10)
					{
						total.Number[j + i] -= 10;
						temp++;
					}
				}
			}

			if (j == lhs.Number.size() - 1)
			{
				total.Number.push_back(temp);
				temp = 0;
			}
		}
	}

	// check if last number of vector(will be first number) is zero
	// if zero, drop number
	if (total.Number[total.Number.size() - 1] == 0)
		total.Number.pop_back();

	// flip back number in vector
	for (int i = 0; i < total.Number.size() / 2; i++)
	{
		temp = total.Number[i];
		total.Number[i] = total.Number[total.Number.size() - 1 - i];
		total.Number[total.Number.size() - 1 - i] = temp;
	}

	return total;
}// end function operator*

HugeInt operator*(HugeInt &lhs, int a)
{
	std::string Temp = std::to_string(a);
	HugeInt  tempA(Temp);

	return (HugeInt(lhs) * HugeInt(tempA));
}

HugeInt operator*(int a, HugeInt &rhs)
{
	return (rhs * a);
}

// overloaded operator=
HugeInt& HugeInt::operator=(const HugeInt& rhs)
{
	Number = rhs.Number;
	return *this;
}

// end function operator=


// overloaded output operator
std::ostream const &operator<<(std::ostream &cout, HugeInt &rhs)
{
	for (int i = 0; i < rhs.Number.size(); i++)
		cout << rhs.Number[i];

	return cout;
}// end function operator<<

