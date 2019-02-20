// Aquare of Asterisks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int stars;

	printf("Enter length of side:\n");
	scanf_s("%d", &stars);

	if (stars < 1)
	{
		stars = 1;
		printf("Invalid Input\nUsing default value 1\n");
	}
	else if (stars > 20)
	{
		stars = 20;
		printf("Invalid Input\nUsing default value 20\n");
	}

	for (int x = 1; x <= stars; x++)
	{
		for (int z = 1; z <= stars; z++)
		{
			if (x == 1 || x == stars || z == 1 || z == stars)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
		
			
	if (1)
    return 0;
}

