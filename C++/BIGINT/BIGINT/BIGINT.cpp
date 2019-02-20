// BIGINT.cpp : Defines the entry point for the console application.

#include "stdafx.h"

const int arraySize = 200;
const int sentinal = -1;

using namespace std;

int getFirstValidPosition(char string[]);
int getSizeOfNumber(int number[]);
void askForNumber(char input[]);
void stringToDecimal(char string[], int decimal[]);
void additionTwoInts(int a[], int b[], int storage[]);
void multiplicationTwoInts(int a[], int b[], int storage[]);
void printOutput(int output[]);
void printOutputCommas(int output[]);
void setArrayToValue(int numberArray[], int value);
void setArrayToValue(char input[], int value);



int _tmain(int argc, char* argv[])
{
	int first[arraySize] = {};
	int second[arraySize] = {};
	int  output[arraySize] = {};

	char input[arraySize] = {};

	setArrayToValue(first, sentinal);
	setArrayToValue(second, sentinal);
	setArrayToValue(output, sentinal);

	cout << "Program Author: Steve Oseguera" << endl;
	cout << "What a disgusting homework assignment...." << endl << endl;

	askForNumber(input);

	stringToDecimal(input, first);

	//Fix v1.1
	setArrayToValue(input, sentinal); // We need to clear the array "input" before asking for another string from the user, because there is data left open of randomness. This function sets the "input" to '-1'. Perfect.

	askForNumber(input);

	stringToDecimal(input, second);

	cout << "Sum: ";

	additionTwoInts(first, second, output);

	printOutput(output);

	cout << "Product: ";

	if (getSizeOfNumber(first) >= getSizeOfNumber(second)) // I want the first number in the arguments to be the larger one.
		multiplicationTwoInts(first, second, output);
	else
		multiplicationTwoInts(second, first, output);

	printOutput(output);

	system("Pause");
}


int getFirstValidPosition(char string[])
{
	for (int x = arraySize - 1; x >= 0; x--)
	{
		if (isdigit(string[x]))
			return x;
	}

	return 0;
}

void askForNumber(char input[])
{
	cout << "Please enter in a large number." << endl;

	cin >> input;
}

void stringToDecimal(char string[], int decimal[])
{
	for (int x = getFirstValidPosition(string), y = arraySize - 1; x >= 0; x--, y--)
	{
		if (isdigit(string[x]))
			decimal[y] = string[x] - '0';
		else
			break;
	}
}

void additionTwoInts(int a[], int b[], int storage[])
{
	int carry = 0;

	setArrayToValue(storage, -1);

	for (int x = arraySize - 1; x >= 0; x--)
	{
		if (a[x] == sentinal && b[x] == sentinal && carry == 0)
			break;

		if (a[x] == sentinal || b[x] == sentinal)
		{
			if (a[x] == sentinal && b[x] == sentinal && carry > 0)
			{
				storage[x] = carry;
				return;
			}

			if (a[x] == sentinal && b[x] >= 0)
				a[x] = 0;

			if (b[x] == sentinal && a[x] >= 0)
				b[x] = 0;
		}

		if ((a[x] + b[x] + carry) >= 10)
		{
			storage[x] = (a[x] + b[x] + carry) % 10;
			carry = (a[x] + b[x] + carry) / 10;
		}
		else
		{
			storage[x] = a[x] + b[x] + carry;
			carry = 0;
		}
	}
}

int getSizeOfNumber(int number[])
{
	for (int x = 0; x <= arraySize - 1; x++)
	{
		if (number[x] > 0)
			return arraySize - x;
	}

	return -1;
}

void setArrayToValue(int numberArray[], int value)
{
	for (int x = arraySize - 1; x >= 0; x--)
		numberArray[x] = static_cast<char>(value);
}

void setArrayToValue(char stringArray[], int value)
{
	for (int x = arraySize - 1; x >= 0; x--)
		stringArray[x] = value;
}

void setupAdditionArray(int Original[arraySize][arraySize], int destination[], int originalSubscript)
{
	setArrayToValue(destination, -1);

	for (int x = arraySize - 1, y = arraySize - 1; x >= 0; x--)
	{
		if (Original[originalSubscript][x] == -1)
			break;
		else
		{
			destination[y] = Original[originalSubscript][x];
			y--;
		}
	}

}

void multiplicationTwoInts(int a[], int b[], int storage[])
{
	int multiplcationResults[arraySize][arraySize] = {};

	int additionNumber1[arraySize]		= {};
	int additionNumber2[arraySize]		= {};
	int tempResultAddition[arraySize]   = {};
	
	int iterations = getSizeOfNumber(b); // I want the b to always be the smaller number, as I did so in main().
	int z = arraySize - 1;
	int zeroToAdd = 0;
	int zerosAdded = 0;

	int carry = 0;

	// Initialize all my arrays to -1, because I like -1 being my sentinal.

	for (int x = arraySize - 1; x >= 0; x--)
		for (int y = arraySize - 1; y >= 0; y--)
			multiplcationResults[x][y] = sentinal;

	setArrayToValue(additionNumber1, sentinal);
	setArrayToValue(additionNumber2, sentinal);
	setArrayToValue(tempResultAddition, sentinal);

	// end intializing arrays.

	if (iterations <= 0) // if our numbers contain no digits, there's nothing to compute, return.
		return;

	for (int x = 0; x < iterations; x++, z--) // Smallest number has "iteration" digits in length
	{
		for (int y = getSizeOfNumber(a) , temp = arraySize - 1; y > 0; y-- , temp--)
		{
			for (; zeroToAdd >= 1; temp--, zeroToAdd--)
			{
				multiplcationResults[z][temp] = 0;
				zerosAdded++;
			}
				
			multiplcationResults[z][temp] = (a[temp + zerosAdded] * b[z] + carry ) % 10;
			carry = (a[temp + zerosAdded] * b[z] + carry ) / 10;

			if ( y - 1 <= 0)
				if (carry > 0)
					multiplcationResults[z][temp - 1] = carry;
				
		}
		zeroToAdd += x + 1;
		zerosAdded = 0;
		carry = 0;
	}

	int resultArray[arraySize] = {};
	int resultArray2[arraySize] = {};

	setArrayToValue(resultArray, sentinal);
	setArrayToValue(resultArray2, sentinal);

	setupAdditionArray(multiplcationResults, additionNumber1, arraySize - 1);
	setupAdditionArray(multiplcationResults, additionNumber2, arraySize - 2);

	additionTwoInts(additionNumber1, additionNumber2, resultArray);

	if (getSizeOfNumber(a) <= 2)
	{
		printOutput(resultArray);
		return;
	}

	else
	{
		for (int x = arraySize - 3; x >= 0; x--)
		{
			setupAdditionArray(multiplcationResults, additionNumber1, x);

			if (x == 0)
				additionTwoInts(additionNumber1, resultArray2, storage);

			else if (x % 2 == 0)
				additionTwoInts(additionNumber1, resultArray2, resultArray);
			else
				additionTwoInts(additionNumber1, resultArray, resultArray2);
		}
	}
}

void printOutput(int output[])
{
	for (int x = 0; x <= arraySize - 1; x++)
	{
		if (output[x] == sentinal)
			continue;
		else
			cout << output[x];
	}

	cout << endl;
}
