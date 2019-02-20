// OperatorOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Cat
{
private:
	int eyes;
	int legs;

public:
	Cat();
	Cat(int eyes, int legs);
	//~Cat();

	//friend std::ostream& operator <<(std::ostream& lhs, TestClass& rhs);

	//friend TestClass operator+(const TestClass& lhs, const TestClass& rhs);

	friend Cat operator+(Cat &lhs, Cat &rhs);
	friend Cat operator+(Cat &lhs, int a);

	friend std::ostream &operator <<(std::ostream &lhs, Cat &rhs);

	int getEyes() { return eyes; };
	int getLegs() { return legs; };
};

Cat::Cat()
{
	this->eyes = 2;
	this->legs = 4;
}

Cat::Cat(int eyes, int legs)
{
	this->eyes = eyes;
	this->legs = legs;
}

std::ostream &operator <<(std::ostream& cout, Cat &rhs)
{
	cout << "...";

	return cout;
}


Cat operator+(Cat &lhs, Cat &rhs)
{

	Cat Tempo;

	Tempo.eyes = lhs.eyes + rhs.eyes;
	Tempo.legs = lhs.legs + rhs.legs;

	return Tempo;

}


int main()
{
	Cat Max(4, 6);
	Cat Sass(5, 9);
	Cat c1;
	Cat *c2 = new Cat();

	std::cout << Max.getEyes() << std::endl;
	std::cout << Max.getLegs() << std::endl;

	//std::cout << Max;

	//c1 = Max + 2;

	std::cout << c1;

	return 0;
}
