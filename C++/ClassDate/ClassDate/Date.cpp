/*
Date.cpp : define functions in Date class.
Author: Steven Oseguera
Project 1: Question 6
10/6/2015
*/


#include "stdafx.h"

using namespace std;

Date::Date(int month, int day, int year)
{
	this->day = day;
	this->year = year;

	if (month > 12 || month < 1)
		this->month = 1;
	else
		this->month = month;
}

void Date::displayDate() { cout << this->month << "//" << this->day << "//" << this->year << endl; }
int Date::getDay() { return this->day; }
int Date::getMonth() { return this->month; }
int Date::getYear() { return this->year; }



