#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Account
{
public:
	Account(int);
	void credit(int);
	void debit(int);
	int getBalance();
private:
	int balance;
};

class Employee
{
public:
	Employee(string, string, int);
	void setFirst(string);
	void setLast(string);
	void setSalary(int);
	string getFirst();
	string getLast();
	int getSalary();
private:
	string firstName;
	string lastName;
	int salary;
};

class GradeBook
{
public:
	GradeBook(string, string);
	void setCourseName(string);
	string getCourseName();
	string getInstructor();
	void setInstructor(string);
	void displayMessage();
private:
	string courseName;
	string instructorName;
};

class Student
{
public:
	Student(string, string, int, int, int);
	string getFirstName();
	string getLastName();
	int getExamScore(int);
	void setFirstName(string);
	void setLastName(string);
	void setExamScore(int, int);
	int getAverage();

private:
	string firstName;
	string lastName;
	int examScores[3];
};

class Credit
{
public:
	Credit::Credit(int, double, double, double, double);
	void Credit::calculateNewBalance();
	void Credit::displayAccount();
private:
	double balance, charges, credit, creditLimit;
	int accountnumber;
};