/*
Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
using namespace std;

namespace sdds
{
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		int len = strlen(MenuContent);
		m_text = new char[len + 1];
		m_noOfSel = NoOfSelections;
		strcpy(m_text,MenuContent);
		m_text[len] = '\0';
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	Menu::Menu(const Menu& src)
	{
		m_text = nullptr;
		*this = src; // This calls the assign operator
	}

	Menu& Menu::operator=(const Menu& src)
	{
		m_noOfSel = src.m_noOfSel;
		if (this != &src)
		{
			if (src.m_text != nullptr)
			{
				delete[] m_text;
				int len = strlen(src.m_text);
				m_text = new char[len + 1];
				strncpy(m_text, src.m_text, len);
				m_text[len] = '\0';
			}
			else
			{
				m_text = nullptr;
			}
		}

		return *this;
	}

	void Menu::display()const
	{
		cout << m_text << endl << "0- Exit" <<endl;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
		return Selection;
	}
}