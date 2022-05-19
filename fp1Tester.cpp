/*
Citation and Sources...
Final Project Milestone 5
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
// Final Project Tester
// file: fp1Tester.cpp
// Version: 1.0
// Date: 2021-06-23
// Author: Fardad
// Description:
// This file tests the Final project
// with no data file
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"
using namespace sdds;
using namespace std;
int main() {
   sdds::debug = true;
   ofstream("data.csv").close();
   PreTriage P("data.csv");
   P.run();
   return 0;
}

