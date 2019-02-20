/*
Main.cpp : tests Date class
Author: Steven Oseguera
Project 1: Question 6
10/6/2015
*/


#include "stdafx.h"

using namespace std;

int main()
{
	Date date(10,6,2015);

	date.displayDate();

	cout << date.getMonth() << "//" << date.getDay() << "//" << date.getYear() << endl;
	if(1)


    return 0;
}

