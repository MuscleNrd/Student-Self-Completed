/*
Palindrome.cpp : User types in a number, program reverses and prints out the number.
Author: Steven Oseguera
Project 1: Question 2
10/6/2015
*/

#include "stdafx.h"


#include <iostream>
using namespace std;


int main()
{

	int number;
	int remainder;
	int reverse = 0;

	cout << "Please enter a five-digit number to be reversed: " << endl;
	cin >> number;

	while (number != 0)
	{
		remainder = number % 10;
		reverse = reverse * 10 + remainder;
		number = number / 10;
	}

	cout << "Reversed number: " << reverse << endl;

}

