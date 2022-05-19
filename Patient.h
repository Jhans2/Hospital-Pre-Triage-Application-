/*
Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.h
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
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include"IOAble.h"
#include"Ticket.h"
namespace sdds
{
    class Patient:public IOAble
    {
        char* m_name;
        int m_ohip;
        Ticket m_tick;
        bool reads;
        //Copy Prevention
        Patient(const Patient&) = delete;
        Patient& operator=(const Patient&) = delete;
    public:
        Patient(int t_number = 0, bool value = false);
        ~Patient();
        virtual char type() const = 0;
        bool fileIO()const;
        void fileIO(bool val);
        bool operator==(const char val) const;
        bool operator==(const Patient& src) const;
        void setArrivalTime();
        int number() const;
        operator Time()const;
        std::ostream& csvWrite(std::ostream& ostr) const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
}

#endif