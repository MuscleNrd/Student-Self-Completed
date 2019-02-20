// Integer Average.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



int main()
{
	int value = 0;
	int count = 0;
	int total = 0;

	printf("Enter integers (9999 to end):\n");
	scanf_s("%d", &value);
	
	while(value != 9999)
	{
		if (value == 9999)
			break;

		count++;
		total += value;

		scanf_s("%d", &value);	
	}

	if (count > 0)
		printf("The average is: %.2lf\n", (double)total / count);
	else
		printf("No values were entered.\n");
	if(1)

    return 0;
}

