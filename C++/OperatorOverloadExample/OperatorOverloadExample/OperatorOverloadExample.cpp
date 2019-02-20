// OperatorOverloadExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class GrassButtAsdfImGay
{
	
};

int main()
{
	Player test;

	test += -1;
	Item item1("OneUp");
	Item item2("OneDown");
	item1[0] = 1337;

	test += 1;
	test += item1;
	test += item2;

	system("pause");
    return 0;
}

