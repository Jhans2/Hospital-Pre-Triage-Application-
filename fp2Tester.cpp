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
// file: fp2Tester.cpp
// Version: 1.0
// Date: 2021-06-23
// Author: Fardad
// Description:
// This file tests the Final project
// overall functionality
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"

using namespace sdds;
using namespace std;

void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void copyFile(const char* des, const char* src) {
   ifstream s(src);
   ofstream d(des);
   char ch = 0;
   while (s.get(ch) && d << ch);
}
int main() {
   sdds::debug = true;
   copyFile("smalldata.csv", "smalldata.csv.bak");
   PreTriage P("smalldata.csv");
   P.run();
   return 0;
}

