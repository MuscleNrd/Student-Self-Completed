// Project 3, Q1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int main()
{
	cout << "Project 3 Question 1!" << endl;
	cout << "There is no user interaction at this time!" << endl << endl;

	BST<string> *bst = new BST<string>();
	bst->add("Atlanta", 10, 240);
	bst->add("Austin", 100, 200);
	bst->add("Boston", 200, 300);
	bst->add("Chicago", 360, 890);
	bst->add("CedarRapids", 205, 400);
	bst->add("Dallas", 300, 450);
	bst->add("Detroit", 150, 360);
	bst->add("NewYork", 50, 270);
	bst->add("LosAngeles", 600, 800);
	bst->add("LasVegas", 580, 780);
	bst->add("PortLand", 650, 830);
	bst->add("Seattle", 680, 780);
	bst->add("SanFrancisco", 600, 800);
	bst->print();
	cout << endl;
	cout << "Nodes count: " << bst->nodesCount();
	cout << endl;
	cout << "Height: " << bst->height();
	cout << endl;
	cout << "Max path: ";
	bst->printMaxPath();
	cout << endl;
	bst->deleteValue("Atlanta");
	cout << "Deleting Atlanta!" << endl;
	bst->print();
	cout << endl;
	system("pause");
	return 0;
}

