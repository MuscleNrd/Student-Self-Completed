/*
Date.h : define Date class.
Author: Steven Oseguera
Project 1: Question 6
10/6/2015
*/

#pragma once

class Date
{
public:
	int getDay();
	int getMonth();
	int getYear();
	void displayDate();
	Date(int, int, int);
private:
	int day;
	int month;
	int year;
};