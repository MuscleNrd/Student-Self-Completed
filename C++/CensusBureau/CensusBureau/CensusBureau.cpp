// CensusBureau.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

const int INFANT = 18;
const int YOUNG = 29;
const int MIDDLEAGED = 50;
const int OLD = 69;
const int REALLYOLD = 70;

map<int, int> organizeValues(int ages[], int size);
map<string, int> organizeStats(std::map<int, int> ageSet);

inline int findAverage(int numbers[], int size);
int* findMode(map<int, int> numbers);
double calculateStandardDeviation(int numbers[], int size);
void printMyCrap(map<int, int> ageSet, map<string, int> statistics, int ages[], int size);

int main()
{
	int ages[] = { 4, 15 ,79, 52, 56, 19, 21, 22, 3, 12, 30, 33, 81, 99, 85, 28, 24, 25, 24, 26, 27, 20, 41, 32, 35, 24, 39, 43, 41, 46, 56, 62, 22, 20, 22, 18, };

	map<int, int> ageSet = organizeValues(ages , sizeof(ages) / sizeof(int)); // Age :: number of people of that age

	map<string, int> statistics = organizeStats(ageSet);

	printMyCrap(ageSet, statistics, ages, sizeof(ages) / sizeof(int));

	cout << "//////////////////////////////////////////////// End Professor's Test" << endl;
	cout << "//////////////////////////////////////////////// Begin user input" << endl;

	int input = 0;
	vector<int> userInput;

	cout << "Enter in ages, enter -1 to stop." << endl;

	while ( input != -1)
	{
		cin >> input;

		if (input == -1)
			break;

		userInput.push_back(input);
	}

	ageSet = organizeValues(&userInput[0], userInput.size());

	statistics = organizeStats(ageSet);

	printMyCrap(ageSet, statistics, &userInput[0], userInput.size());
	
	system("Pause");
    return 0;
}

void printMyCrap(map<int,int> ageSet , map<string,int> statistics, int ages[], int size)
{
	for (map<string, int>::iterator it = statistics.begin(); it != statistics.end(); it++)
		cout << "Amount of " << it->first << " -> " << it->second << endl;

	cout << "Printing Mode(s): ";

	for (int x = 0; x < findMode(ageSet)[0]; x++)
		cout << findMode(ageSet)[x + 1] << "  ";

	cout << endl;

	cout << "Average: ";

	cout << findAverage(ages, size);

	cout << endl;

	cout << "Standard Deviation: ";

	cout << calculateStandardDeviation(ages, size);

	cout << endl;
	cout << endl;
}

map<int,int> organizeValues(int ages[], int size)
{
	map<int, int> ageSet;

	for (int x = 0; x < size ; x++)
	{
		if (ageSet.find(ages[x]) == ageSet.end())
			ageSet[ages[x]] = 1;
		else if (ageSet.find(ages[x]) != ageSet.end())
			ageSet[ages[x]]++;
	}

	return ageSet;

}

map<string,int> organizeStats(std::map<int,int> ageSet)
{
	map<string, int> stats;

	stats["INFANT"] = 0;
	stats["YOUNG"] = 0;
	stats["MIDDLEAGED"] = 0;
	stats["OLD"] = 0;
	stats["REALLYOLD"] = 0;

	map<int, int>::iterator it;

	for (it = ageSet.begin(); it != ageSet.end(); ++it)
	{
		if (it->first > 0 && it->first < INFANT)
			stats["INFANT"] += it->second;

		else if (it->first > INFANT && it->first < YOUNG)
			stats["YOUNG"] += it->second;

		else if (it->first > YOUNG && it->first < MIDDLEAGED)
			stats["MIDDLEAGED"] += it->second;

		else if (it->first > MIDDLEAGED && it->first < REALLYOLD)
			stats["OLD"] += it->second;

		else if (it->first >= REALLYOLD)
			stats["REALLYOLD"] += it->second;
	}

	return stats;
	
}

inline int findAverage(int numbers[], int size)
{
	int a = 0;

	for (int x = 0; x < size; x++)
		a += numbers[x];

	return a / size;
}

int* findMode(map<int,int> numbers)
{
	
	int amountSame = 0;
	int mostCommon = 0;

	for (map<int, int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (it->second > mostCommon)
			mostCommon = it->second;
	}

	for (map<int, int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (it->second == mostCommon)
			amountSame++;
	}

	int * modes = new int[amountSame + 1];
	modes[0] = amountSame;

	int counter = 1;

	for (map<int, int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (it->second == mostCommon)
		{
			modes[counter] = it->first;
			counter++;
		}
	}
	return modes;
}


double calculateStandardDeviation(int numbers[], int size)
{
	int average = findAverage(numbers, size);
	double y = 0;

	for (int x = 0; x < size; x++)
		y += (pow(numbers[x] - average, 2));

	y /= size;

	y = sqrt(y);

	return y;
}