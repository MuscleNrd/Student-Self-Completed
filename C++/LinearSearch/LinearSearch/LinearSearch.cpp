// LinearSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

void recursiveLinearSearch(int numbersA[], int key, int	 size);
void regularLinearSearch(int numbersA[], int keys[], int numSize, int keySize);

int main()
{
	int numbersA[] = { 1, 93, 5, 78, 9, 12, 13, 17, 19, 20, 25, 48, 56, 7, 81, 89, 2, 96, 9 };

	int keys[] = { 9, 24, 81 };

	cout << "Regular Linear Search:" << endl << endl;
	regularLinearSearch(numbersA,  keys, sizeof(numbersA) / sizeof(int), sizeof(keys) / sizeof(int));

	cout << endl << "END Regular Linear Search" << endl << endl;

	cout << "Recursive Linear Search: " << endl;
	recursiveLinearSearch(numbersA, keys[0], sizeof(numbersA) / sizeof(int));
	recursiveLinearSearch(numbersA, keys[1], sizeof(numbersA) / sizeof(int));
	recursiveLinearSearch(numbersA, keys[2], sizeof(numbersA) / sizeof(int));

	cout << endl << "END Recursive Linear Search" << endl;

	system("Pause");
	 return 0;
}

void recursiveLinearSearch(int numbersA[], int key, int	 size)
{
	if (key == numbersA[size])
		cout << "Key " << key << " found at: " << size << endl;
    if (size - 1 >= 0)
		recursiveLinearSearch(numbersA, key, size - 1);
}

void regularLinearSearch(int numbersA[], int keys[], int numSize, int keySize)
{
	for (int y = 0; y < keySize; y++)
	{
		for (int x = 0; x < numSize; x++)
		{
			if (keys[y] == numbersA[x])
				cout << "Key " << keys[y] << " found at: " << "Slot " << x << endl;
		}
	}
}

