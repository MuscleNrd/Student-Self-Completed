// BinarySearch.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"

void sortAscending(int numbers[], int size);
bool isSmallest(int number, int numbers[], int size, int startingSlot);

int main()
{
	int ages[] = { 4, 15, 79, 52, 56, 19, 21, 22, 3, 12, 30, 33, 81, 99, 85, 28, 24, 25, 24, 26, 27, 20, 41, 32, 35, 24, 39, 43, 41, 46, 56, 62, 22, 20, 22, 18 };

	sortAscending(ages, sizeof(ages) / sizeof(int));

	system("pause");

	return 0;
}

void sortAscending(int numbers[], int size)
{
	int a = 0;
	int b = 0;
	int correctSlots = 0;

	for (int x = 0; x < size; x++)
	{
		a = numbers[x];

		for (int y = 1 + correctSlots; y < size; y++)
		{
			b = numbers[y];

			if (a > b && isSmallest(b, numbers, size, correctSlots))
			{
				numbers[x] = b;
				numbers[y] = a;
				correctSlots++;
				break;
			}

			if (y == size - 1)
				correctSlots++;
		}
	}
}

bool isSmallest(int number, int numbers[], int size, int startingSlot)
{
	for (int x = startingSlot; x < size; x++)
	{
		if (number > numbers[x])
			return false;
	}
	return true;
}
