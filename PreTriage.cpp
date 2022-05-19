/*
Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#include <fstream>
#include <cstring>
#include "Menu.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "Patient.h"
#include "PreTriage.h"
#include "Time.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename) :m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		load();
	}

	PreTriage::~PreTriage()
	{
		ofstream fout;
		fout.open(m_dataFilename);
		fout << m_averCovidWait << ',' << m_averTriageWait;
		fout << endl;
		for (int i = 0; i < m_lineupSize; i++)
		{
			m_lineup[i]->csvWrite(fout);
			fout << "\n";
		}

		cout << "Saving Average Wait Times,\n";
		cout << "   COVID Test: " << m_averCovidWait << "\n";
		cout << "   Triage: " << m_averTriageWait << "\n";
		cout << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++)
		{
			cout << (i + 1) << "- ";
			m_lineup[i]->csvWrite(cout);
			cout << "\n";
		}
		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
		}
		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		cout << "done!" << endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		unsigned int patients = 0;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type())
			{
				patients++;
			}
		}
		return p.type() == 'C' ? m_averCovidWait * patients : m_averTriageWait * patients;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		int min = getTime();
		if (p.type() == 'C')
		{
			m_averCovidWait = ((min - int(Time(p))) + (int(m_averCovidWait) * (p.number() - 1))) / p.number();
		}
		else if (p.type() == 'T')
		{
			m_averTriageWait = ((min - int(Time(p))) + (int(m_averTriageWait) * (p.number() - 1))) / p.number();
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int find = 0, flag = 0;
		do
		{
			for (int i = 0; i < m_lineupSize && flag != 1; i++)
			{
				if (m_lineup[i]->type() == type)
				{
					find = i;
					flag = 1;
				}
				else
				{
					find = -1;
				}
			}

		} while (flag == 0);

		return find;
	}

	void PreTriage::load()
	{
		ifstream fin;
		fin.open(m_dataFilename);
		Patient* admit = nullptr;
		char read = 'x';
		char read2 = 'x';
		cout << "Loading data..." << endl;
		if (fin.is_open())
		{
			m_averCovidWait.read(fin);
			fin >> read2;
			m_averTriageWait.read(fin);
			fin.ignore();
			for (int i = 0; i < maxNoOfPatients && !fin.fail(); i++)
			{
				fin >> read >> read2;
				if (read == 'C')
				{
					admit = new CovidPatient();
				}
				else if (read == 'T')
				{
					admit = new TriagePatient();
				}
				if (read == 'C' || read == 'T')
				{
					admit->fileIO(true);
					admit->csvRead(fin);
					admit->fileIO(false);
					m_lineup[i] = admit;
					m_lineupSize++;
					read = 'x';
				}
			}
		}
		if (m_lineupSize == 0)
		{
			cout << "No data or bad data file!" << endl << endl;
		}
		else
		{
			if (m_lineupSize == maxNoOfPatients)
			{
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}
			cout << m_lineupSize << " Records imported..." << endl << endl;
		}
	}

	void PreTriage::reg()
	{
		int selection = -1;
		if (m_lineupSize == maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{

			m_pMenu >> selection;
			if (selection != 0)
			{
				if (selection == 1)
				{
					m_lineup[m_lineupSize] = new CovidPatient();
				}
				else if (selection == 2)
				{
					m_lineup[m_lineupSize] = new TriagePatient();
				}
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(cin);
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: ";
				cout << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				m_lineupSize++;
				cout << "******************************************" << endl << endl;
			}
		}
	}

	void PreTriage::admit()
	{
		int selection = -1;
		int finding = -1;
		char local = 'x';

		m_pMenu >> selection;
		if (selection == 1)
		{
			local = 'C';
		}
		else if (selection == 2)
		{
			local = 'T';
		}
		if (selection != 0)
		{
			finding = indexOfFirstInLine(local);
			if (finding >= 0)
			{
				cout << endl << "******************************************" << endl;
				m_lineup[finding]->fileIO(false);
				cout << "Calling for ";
				m_lineup[finding]->write(cout);
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[finding]);
				removePatientFromLineup(finding);
			}
		}
	}

	void PreTriage::run(void)
	{
		int selection = -1;

		do
		{
			m_appMenu >> selection;
			if (selection == 1)
			{
				reg();
			}
			else if (selection == 2)
			{
				admit();
			}

		} while (selection != 0);
	}
}