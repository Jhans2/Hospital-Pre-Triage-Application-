/*
Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
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
#include "Time.h"
#include "utils.h"
using namespace std;

namespace sdds {

	Time& Time::setToNow()
	{	
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hours = m_min / 60;
		int minutes = m_min % 60;
		ostr.width(2);
		ostr.fill('0');

		ostr << hours << ":";

		ostr.width(2);
		ostr.fill('0');

		ostr << minutes;

		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hour = 0, minutes = 0;
		char sign = 'x';

		istr >> hour >> sign >> minutes;

		if (hour < 0)
		{
			istr.setstate(ios::failbit);
		}


		else if (sign != ':')
		{
			istr.setstate(ios::failbit);
		}


		else if (minutes < 0)
		{			
			istr.setstate(ios::failbit);
		}
		else
		{
			m_min = hour * 60 + minutes;
		}
		return istr;
	}

	Time& Time::operator-= (const Time& D)
	{
		if (m_min > D.m_min)
		{
			m_min = m_min - D.m_min;
		}
		else if (m_min < D.m_min)
		{
			if (D.m_min > 1440)
			{
				m_min = ((m_min + 1440 + 1440) - D.m_min);
			}
			else
			{
				m_min = ((m_min + 1440) - D.m_min);
			}
		}
		return *this;
	}

	Time Time::operator-(const Time& D)const
	{
		Time min;
		if (m_min > D.m_min)
		{
			min.m_min = m_min - D.m_min;
		}
		else if (m_min < D.m_min)
		{
			if (D.m_min > 1440)
			{
				min = ((m_min + 1440 + 1440) - D.m_min);
			}
			else
			{
				min = ((m_min + 1440) - D.m_min);
			}

		}
		return min;
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min = m_min + D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const
	{
		Time tim;
		tim.m_min = m_min + D.m_min;
		return tim;
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time& Time::operator *= (unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const
	{
		Time x;
		x.m_min = m_min * val;
		return x;
	}

	Time& Time::operator /= (unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time::operator /(unsigned int val)const
	{
		Time y;
		y.m_min = m_min / val;
		return y;
	}

	Time::operator int()const
	{
		return m_min;
	}

	Time::operator unsigned int()const
	{
		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}