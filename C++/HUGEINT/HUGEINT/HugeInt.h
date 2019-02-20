#pragma once
#include "stdafx.h"

class HugeInt
{
private:
	std::vector <int> Number;

public:

	HugeInt(std::string);
	HugeInt();

	friend HugeInt const &operator/(HugeInt &lhs, HugeInt &rhs);
	friend HugeInt operator*(HugeInt &lhs, HugeInt &rhs);
	friend HugeInt operator*(HugeInt &lhs, int);
	friend HugeInt operator*(int, HugeInt &rhs);
	friend HugeInt operator-(HugeInt &lhs, HugeInt &rhs);


	friend bool const &operator>(HugeInt &lhs, HugeInt &rhs);
	friend std::ostream const &operator<<(std::ostream &cout, HugeInt &rhs);
	friend bool const &operator<(HugeInt &lhs, HugeInt &rhs);

	HugeInt &operator=(const HugeInt& rhs);
	friend bool const &operator==(HugeInt &lhs, HugeInt &rhs);

};