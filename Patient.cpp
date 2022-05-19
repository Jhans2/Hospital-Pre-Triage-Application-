/*
Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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
#include "Patient.h"
#include "Ticket.h"
using namespace std;

namespace sdds
{
	Patient::Patient(int t_number, bool value):m_tick(t_number)
	{
		m_name = nullptr;
		m_ohip = 0;
		reads = value;
	}

	Patient::~Patient()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::fileIO()const
	{
		return reads;
	}

	void Patient::fileIO(bool val)
	{
		reads = val;
	}

	bool Patient::operator==(const char val) const
	{
		return (type()==val);
	}

    bool Patient::operator==(const Patient& src) const
	{
		return type()==src.type();
	}


	void Patient::setArrivalTime()
	{
		m_tick.resetTime();
	}

	Patient::operator Time() const
	{
		return Time(m_tick);
	}

	int Patient::number() const
	{
		return m_tick.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << "," << m_name << "," << m_ohip << ",";
		m_tick.csvWrite(ostr);
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{	
		delete[] m_name;
		m_name = getcstr(nullptr,istr,',');
		istr >> m_ohip;
		istr.ignore();
		m_tick.csvRead(istr);
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		char hi[26];
		strncpy(hi,m_name,25);
		hi[25] = '\0';
		m_tick.write(ostr);
		ostr << endl;
		ostr << hi;
		ostr << ", OHIP: " << m_ohip;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		delete[] m_name;
		m_name = getcstr("Name: ", istr, '\n');
		m_ohip = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
		return istr;
	}
}