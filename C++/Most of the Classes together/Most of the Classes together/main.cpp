// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	Account Steve(100);
	GradeBook CSCI("CSCI 140 Introduction to C++ Programming", "Professor POP");

	printf("Steve's balance: $%d\n", Steve.getBalance());
	Steve.debit(50);
	Steve.credit(100);
	printf("Steve's balance: $%d\n", Steve.getBalance());
	CSCI.displayMessage();

	CSCI.setInstructor("Professor Steve");
	CSCI.displayMessage();

	//// Employee

	Employee Steven("Steve", "Oseguera", 120000);
	Employee Jackie("Jackie", "Dagdigian", 125000);

	printf("Employee Steven: %s - %s - %d\n", Steven.getFirst().data(), Steven.getLast().data(), Steven.getSalary());
	printf("Employee Jackie: %s - %s - %d\n", Jackie.getFirst().data(), Jackie.getLast().data(), Jackie.getSalary());

	Steven.setSalary(Steven.getSalary() * 1.10);
	Jackie.setSalary(Jackie.getSalary() * 1.10);

	printf("Employee Steven: %s - %s - %d\n", Steven.getFirst().data(), Steven.getLast().data(), Steven.getSalary());
	printf("Employee Jackie: %s - %s - %d\n", Jackie.getFirst().data(), Jackie.getLast().data(), Jackie.getSalary());

	//// Student

	Student John("John", "Cena", 98, 54, 99);

	printf("Student John: %s - %s - %d - %d - %d\n", John.getFirstName().data(), John.getLastName().data(), John.getExamScore(0), John.getExamScore(1), John.getExamScore(2));
	John.setFirstName("Steve");
	John.setLastName("Oseguera");
	printf("Student John: %s - %s - %d - %d - %d\n", John.getFirstName().data(), John.getLastName().data(), John.getExamScore(0), John.getExamScore(1), John.getExamScore(2));
	printf("Grade Average: %d\n", John.getAverage());

	////DepartmentStore

	int account = 0;
	double balance, charges, credit, creditLimit;

	while (account != -1)
	{
		printf("Enter account number (-1 to end):\n");
		scanf_s("%d", &account);
		if (account == -1)
			break;
		printf("Enter beginining balance:\n");
		scanf_s("%lf", &balance);
		printf("Enter total charges:\n");
		scanf_s("%lf", &charges);
		printf("Enter total credit:\n");
		scanf_s("%lf", &credit);
		printf("Enter credit limit:\n");
		scanf_s("%lf", &creditLimit);

		Credit Test(account, charges, balance, credit, creditLimit);
		Test.calculateNewBalance();
	}



	if (1)
		return 0;
}

