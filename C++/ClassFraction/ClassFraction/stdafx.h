// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>



// TODO: reference additional headers your program requires here

class fraction
{
private:
	int numberator;
	int denominator;
public:
	fraction(int, int);
	int getDenominator();
	int getNumerator();
	void print();

};