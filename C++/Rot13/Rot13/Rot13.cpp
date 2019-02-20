// Rot13.cpp : Defines the entry point for the console application.


#include "stdafx.h"
using namespace std;


string encryptDecrypt(bool Encrypt, string Test, int key)
{
	// Rotate the characters how many? Rot - 13 default is, well, 13
	key %= 26;

	if (Encrypt)
	{
		for (int x = 0; x < Test.length(); x++)
		{
			if (isalpha(Test.at(x)))
			{
				if (islower(Test.at(x)))
				{
					if ((Test.at(x) + key) <= 122) // Make sure we don't go over 122, if TRUE we are safe to add.
						Test.at(x) += key;// If we know we don't go over 122, just simply add shift.

					else
					{
						if (Test.at(x) + key <= 122)
							Test.at(x) += key;
						else
							Test.at(x) = 96 + key - (122 - Test.at(x));

					}
				}
				else
				{
					if ((Test.at(x) + key) <= 90) // Make sure we don't go over 122, if TRUE we are safe to add.
						Test.at(x) += key;// If we know we don't go over 122, just simply add shift.
					else
					{
						if (Test.at(x) + key <= 90)
							Test.at(x) += key;
						else
							Test.at(x) = 64 + key - (90 - Test.at(x));

					}
				}
			}
		}
		return Test;
	}

	else
	{
		for (int x = 0; x < Test.length(); x++)
		{
			if (isalpha(Test.at(x)))
			{
				if (islower(Test.at(x)))
				{
					if ((Test.at(x) - key) >= 97) // Make sure we don't go over 122, if TRUE we are safe to add.
						Test.at(x) -= key;// If we know we don't go over 122, just simply add shift.
					else
					{
						if (Test.at(x) - key >= 98)
							Test.at(x) -= key;
						else
							Test.at(x) = 123 - key + (Test.at(x) - 97);
					}
				}
				else
				{
					if ((Test.at(x) - key) >= 65) // Make sure we don't go over 122, if TRUE we are safe to add.
						Test.at(x) -= key;// If we know we don't go over 122, just simply add shift.
					else
					{
						if (Test.at(x) - key >= 66)
							Test.at(x) -= key;
						else
							Test.at(x) = 91 - key + (Test.at(x) - 65);
					}
				}
			}
		}
		return Test;
	}
}

//////////////////////////////////////// THIS IS THE MAIN ////////////////////////////////////////
int main()
{
	// 'a' +  3 == 100
	char input[256];
	int key = 0;

	string Test = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	cout << "Enter a string to encrypt:" << endl;

	cin.getline(input, sizeof(input));
	Test = input;

	cout << "Enter the key for the cipher: " << endl;
	cin >> key;

	cout << "Before: " << Test << endl;

	Test = encryptDecrypt(true, Test, key); // True means encrypt

	cout << "After: " << Test << endl;

	cout << "Decrypt: " << encryptDecrypt(false, Test, key) << endl; // False decrypt


	if (1)
	{
		
	}
}

//////////////////////////////////////// THIS IS THE MAIN ////////////////////////////////////////


