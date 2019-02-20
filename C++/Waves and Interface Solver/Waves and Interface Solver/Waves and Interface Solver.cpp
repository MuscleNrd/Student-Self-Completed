// Waves and Interface Solver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>


int main()
{
	std::map<char, double> variables;
	std::map<char, double> variables_to_find;
	double solution = 0;
	double input = 0;
	bool isVariableToFind = false;
	const int UNKNOWN = -1;

	std::string f = "Hz";
	std::string d = "m";
	std::string L = "m";
	std::string v = "m/s";
	std::string n = "nodal line";
	std::string x = "m";
	std::string l = "m";

	variables.insert_or_assign('f', 0);// frequency that the sources are giving off.
	variables.insert_or_assign('d', 0);// distance sources are spaced apart
	variables.insert_or_assign('L', 0);// distance from mid point of sound sources
	variables.insert_or_assign('v', 0);// given speed
	variables.insert_or_assign('n', 0);// the nodal line
	variables.insert_or_assign('x', 0);// distance from center line
	variables.insert_or_assign('l', 0);// lambda

	std::cout << "Waves and Intereference Solver v1.0 \n\nBy Steve Oseguera\n\n";

	std::cout << "Enter " << UNKNOWN << " if unknown. \n";

	for (const auto &pair : variables)
	{
		static int counter = 0;

		if (pair.first == 'l')
			std::cout << "Please enter value for variable '" << "lambda" << "' : ";
		else
			std::cout << "Please enter value for variable '" << pair.first << "' : ";

		std::cin >> input; 
		std::cout << std::endl;

		if (input == UNKNOWN)
		{
			isVariableToFind = true;
			variables_to_find.insert_or_assign(pair.first, 0);
		}

		variables.insert_or_assign(pair.first, input);
	}

	/// Mathmatical part, lets find out which variable needs to be found.

	// Solve for lambda parts
	// If f or l are unknown, attempt to find them through means of algebra. f = v / l  or l = v / f

	if (variables['f'] == UNKNOWN && variables['l'] == UNKNOWN)
	{
		if (variables['x'] != UNKNOWN || variables['d'] != UNKNOWN || variables['L'] != UNKNOWN || variables['n'] != UNKNOWN)
		{
			variables['l'] = ((variables['x'] * variables['d']) / (variables['L'] * (variables['n'] - 0.5)));
			variables_to_find['l'] = variables['l'];

			//since I found 'l' or lambda, I can now solve for 'f' or frequency if it's unknown.
			if (variables['f'] == UNKNOWN)
			{
				variables['f'] = variables['v'] / variables['l'];
				variables_to_find['f'] = variables['f'];
			}
		}
	}


	if (variables['f'] != UNKNOWN && variables['l'] == UNKNOWN)
	{
		variables['l'] = variables['v'] / variables['f'];
		variables_to_find['l'] = variables['l'];
	}
	// Done

	//Some assumptions to haveing all variables, let's solve for a missing one.
	if (variables['x'] == UNKNOWN || variables['d'] == UNKNOWN || variables['L'] == UNKNOWN || variables['n'] == UNKNOWN)
	{
		if (variables['x'] == UNKNOWN)
		{
			variables['x'] = ((variables['L'] * variables['l'] * (variables['n'] - 0.5)) / variables['d']);
			variables_to_find['x'] = variables['x'];
		}

		if (variables['d'] == UNKNOWN)
		{
			variables['d'] = ((variables['L'] * variables['l'] * (variables['n'] - 0.5)) / variables['x']);
			variables_to_find['d'] = variables['d'];
		}

		if (variables['L'] == UNKNOWN)
		{
			variables['L'] = ((variables['x'] * variables['d']) / (variables['l'] * (variables['n'] - 0.5)));
			variables_to_find['L'] = variables['L'];
		}

		if (variables['n'] == UNKNOWN)
		{
			variables['n'] = ((variables['d'] * variables['x']) / (variables['L'] * variables['l']) + 0.5);
			variables_to_find['n'] = variables['n'];
		}
	}	
	// Done

	for (const auto &pair : variables_to_find)
	{
		std::cout << pair.first << " = " << pair.second;

		if (pair.first == 'f')
			std::cout << f;
		else if (pair.first == 'd')
			std::cout << d;
		else if (pair.first == 'n')
			std::cout << n;
		else if (pair.first == 'L')
			std::cout << L;
		else if (pair.first == 'l')
			std::cout << l;
		else if (pair.first == 'x')
			std::cout << x;

		std::cout << std::endl;
	}
		

	system("pause");

    return 0;
}

