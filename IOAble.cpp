/*
Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
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
#include "IOAble.h"
using namespace std;

namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const IOAble& D)
	{
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, IOAble& D)
	{
		return D.read(istr);
	}
}