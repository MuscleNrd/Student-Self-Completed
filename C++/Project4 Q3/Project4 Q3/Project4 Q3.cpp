// Project4 Q3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Project4 Q3.h"
#define VERSION "v1.0"
using namespace std;

std::string current_working_directory(); // Grabbing directory that the .exe is ran from to obtain a file.

int main()
{
	ofstream outputFile;
	bool writeToFile = false;
	map<char, int> Test;
	map<char, int>::iterator it;

	string iterator;
	string filePath;
	string pathWay = current_working_directory();
	pathWay += "\\"; // Adding trailing slash to my directory, so all the user has to type is the file name itself.
	string FileName;

	cout << "Welcome to Character Frequency Counter! " << VERSION << endl;
	cout << "Please enter the file name to traverse!" << endl;

	cout << pathWay << endl;

	getline(cin, FileName);

	pathWay += FileName;
	
	cout << pathWay << endl;

	fstream fileOpener(pathWay.c_str());

	if (fileOpener.is_open())
		cout << "File " << filePath << " is successfully opened!" << endl;
	else
		cout << "Failed to open!" << endl;

	while (getline(fileOpener, iterator))
	{
		for (int x = 0, z = iterator.size(); x < z; x++)
		{
			it = Test.find(iterator[x]);
			if (it != Test.end())
				Test.at(iterator[x])++;
			else
				Test.insert(std::pair<char, int>(tolower(iterator[x]), 1));
		}
	}

	cout << "Write results to disk? Y/N?" << endl;

	getline(cin, FileName);

	if (tolower(FileName.at(0)) == 'y')
	{
		writeToFile = true;

		cout << "File Name?" << endl;

		getline(cin, FileName);

		outputFile.open(FileName);
	}


		

	for (int x = 'a'; x <= 'z'; x++)
	{
		it = Test.find(x);
		if (it != Test.end())
		{
			cout << char(x) << ": " << Test.at(x) << " entries!" << endl;

			if (writeToFile)
				outputFile << char(x) << ": " << Test.at(x) << " entries!" << endl;
		}
	}

	fileOpener.close();
	outputFile.close();

	system("pause");

    return 0;
}


std::string current_working_directory()
{
	char* cwd = _getcwd(0, 0); // get current directory
	std::string working_directory(cwd);
	std::free(cwd);
	return working_directory;
}

