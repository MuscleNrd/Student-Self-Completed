#include "stdafx.h"
using namespace std;

Account::Account(int initialBalance)// Constructor
{
	balance = 0;//

	if (initialBalance > 0)
		balance = initialBalance;
	else if (initialBalance < 0)
		printf("Error: Initial balance cannot be negative.\n");
}

void Account::debit(int amount) { balance -= amount; }
void Account::credit(int amount) { balance += amount; }
int Account::getBalance() { return balance; }


GradeBook::GradeBook(string course, string instructor)
{
	setCourseName(course);
	setInstructor(instructor);
}

void GradeBook::setCourseName(string course) { courseName = course; }
string GradeBook::getCourseName() { return courseName; }
string GradeBook::getInstructor() { return this->instructorName; }
void GradeBook::setInstructor(string instructor) { instructorName = instructor; }
void GradeBook::displayMessage() { printf("Welcome to the gradebook for %s!\nThis course is ran by: %s!\n", getCourseName().data(), getInstructor().data()); }


Employee::Employee(string name, string last, int salary)
{
	this->firstName = name;
	this->lastName = last;
	if (salary > 0)
		this->salary = salary;
}

void Employee::setFirst(string name) { this->firstName = name; }
void Employee::setLast(string name) { this->lastName = name; }
void Employee::setSalary(int salary) { this->salary = salary; }
string Employee::getFirst() { return this->firstName; }
string Employee::getLast() { return this->lastName; }
int Employee::getSalary() { return this->salary; }

Student::Student(string name, string lastName, int grade1, int grade2, int grade3)
{
	this->firstName = name;
	this->lastName = lastName;
	this->examScores[0] = grade1;
	this->examScores[1] = grade2;
	this->examScores[2] = grade3;
}
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
int Student::getExamScore(int whichExam) { return this->examScores[whichExam]; }
void Student::setExamScore(int whichExam, int newScore) { this->examScores[whichExam] = newScore; }
void Student::setFirstName(string name) { this->firstName = name; }
void Student::setLastName(string name) { this->lastName = name; }

int Student::getAverage()
{
	int avg = 0;

	for (int x = 0; x <= 2; x++)
		avg += this->examScores[x];
	return (avg / 3);
}

Credit::Credit(int account, double charges, double balance, double credit, double creditLimit)
{
	this->accountnumber = account;
	this->charges = charges;
	this->balance = balance;
	this->credit = credit;
	this->creditLimit = creditLimit;
}

void Credit::calculateNewBalance() { this->balance = this->balance + this->charges - this->credit; }
void Credit::displayAccount()
{
	cout << setprecision(2) << fixed << "New balance is: " << this->balance << endl;
	cout << "Account: " << this->accountnumber << endl;
	cout << "Credit Limit: " << this->creditLimit << endl;
	cout << "Balance: " << this->balance << endl;

	if (this->balance > this->creditLimit)
		cout << "Credit Limit Exceeded.";
}










