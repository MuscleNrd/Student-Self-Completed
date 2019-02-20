#pragma once
#include "stdafx.h"
#include <string>


class Item
{
private:
	std::string Itemtype;
	int traits[10] = { 0 };
public:
	Item(std::string);
	std::string getType() { return Itemtype.c_str(); }
	int& operator[](const int);
};

class Player
{
private:
	int HP;
	int MP;
	int lives;
	int Stamina;
public:
	void operator+=(const int);
	void operator+=(Item&);
	

	Player();
	//~Player();
};

