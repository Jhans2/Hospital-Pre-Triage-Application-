/*
Citation and Sources...
Final Project Milestone 5
Module: Utils
Filename: Utils.cpp
Version 1.0
Author:	Jatin Hans
Student Id: 141560201
Student Email : jhans2@myseneca.ca
Course Section: ZCC
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/30  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
	bool debug = false; // made global in utils.h
	int getTime()
	{
		int mins = -1;
		if (debug)
		{
			Time t(0);
			cout << "Enter current time: ";
			do
			{
				cin.clear();
				cin >> t; // needs extraction operator overloaded for Time
				if (!cin)
				{
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else
				{
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else
		{
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}

	int getInt(const char* prompt)
	{
		int value = 0;
		int flag = 1;
		if (prompt != nullptr)
		{
			cout << prompt;
		}
		do
		{
			cin >> value;
			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}
			else if (!(cin.fail()) && char(cin.get()) != '\n')
			{
				cout << "Enter only an integer, try again: ";
				cin.ignore(2000, '\n');
			}
			else
			{
				flag = 0;
			}
		} while (flag);

		return value;
	}

	int getInt(
		int min,                            // minimum acceptable value
		int max,                            // maximum acceptable value
		const char* prompt,      // User entry prompt
		const char* errorMessage, // Invalid value error message,
		bool showRangeAtError        // display the range if invalud value entered
	)
	{
		int value = 0;
		int flag = 1;
		if (prompt != nullptr)
		{
			cout << prompt;
		}

		do
		{
			cin >> value;
			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}
			else if (char(cin.get()) != '\n')
			{
				cout << "Enter only an integer, try again: ";
				cin.ignore(2000, '\n');
			}
			else
			{
				if (value >= min && value <= max)
				{
					flag = 0;
				}
				else
				{
					if (errorMessage != nullptr)
					{
						cout << errorMessage;
					}

					if (showRangeAtError)
					{
						cout << "[" << min << " <= "
							<< "value"
							<< " <= " << max << "]: ";
					}
				}

			}
		} while (flag);

		return value;
	}

	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		char* mystring = nullptr;
		string mystr;
		if (prompt != nullptr)
		{
			cout << prompt;
		}
		if (getline(istr, mystr, delimiter))
		{
			mystring = new char[mystr.length() + 1];
			strcpy(mystring, mystr.c_str());
		}
		return mystring;
	}

}