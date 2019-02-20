#include "stdafx.h"

int main()
{
	std::string first;
	std::string second;

	std::cout << "Enter first large integer: ";
	std::cin >> first;
	std::cout << "Enter second large integer: ";
	std::cin >> second;

	HugeInt a(first);
	HugeInt b(second);


	HugeInt c;
	HugeInt d;

	if (a == b)
		std::cout << "A == B" << std::endl;

	std::cout << c;
	std::cout << std::endl;

	c = c * 5;

	std::cout << c;
	std::cout << std::endl;

	c = 10 * c;

	std::cout << c;
	std::cout << std::endl;

	d = c;

	std::cout << d;
	std::cout << std::endl;

}// end main