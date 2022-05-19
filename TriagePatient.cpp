/*
Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include "CovidPatient.h"
#include "Patient.h"
#include "TriagePatient.h"
using namespace std;

namespace sdds 
{
   int nextTriageTicket = 1;
	
   TriagePatient::TriagePatient():Patient(nextTriageTicket)
   {
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;
       m_symptoms = nullptr;
   }

   char TriagePatient::type() const
   {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
   {
	   Patient::csvWrite(ostr);
	   ostr << "," << m_symptoms;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
	   delete[] m_symptoms;
	   Patient::csvRead(istr);
	   istr.ignore();
	   m_symptoms = getcstr(nullptr, istr, '\n');
	   nextTriageTicket = Patient::number();
	   nextTriageTicket++;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const
   {
	   if (fileIO())
	   {
		   csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl;
		   ostr << "Symptoms: ";
		   ostr << m_symptoms << endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr)
   {
	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   delete[] m_symptoms;
		   Patient::read(istr);
		   cout << "Symptoms: ";
		   m_symptoms = getcstr(nullptr, istr, '\n');
	   }
	   return istr;
   }

}