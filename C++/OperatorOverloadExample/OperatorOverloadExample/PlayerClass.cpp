#include "stdafx.h"

Player::Player()
{
	HP = 100;
	MP = 100;
	lives = 3;
	Stamina = 100;
}

void Player::operator+=(const int lives)
{
	this->lives += lives;
}

void Player::operator+=(Item &item)
{
	if (_strcmpi(item.getType().c_str(), "OneUp") == 0)
		this->lives++;

	else if (_strcmpi(item.getType().c_str(), "OneDown") == 0)
		this->lives--;
}

Item::Item(std::string input)
{
	Itemtype = input;
	this->traits[0] = { 100 };
}

int& Item::operator[](int subscript)
{
	return traits[subscript];
}