
#include <iostream>

class TestClass
{
private:
	int number;
	int number2;

public:
	friend std::ostream& operator <<(std::ostream& lhs, TestClass& rhs);
	friend std::istream& operator >>(std::istream& input, TestClass& rhs);
	friend TestClass operator+(const TestClass& lhs, const TestClass& rhs);

	int getNumber1();
	int getNumber2();
	void setNumber1(int x) { number = x; };
	void setNumber2(int x) { number2 = x; };

	TestClass(int a, int b);
	TestClass();
	//	~TestClass();
};