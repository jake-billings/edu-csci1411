#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Bank.h"
#include <vector>
void bubbleSort(vector<Bank> & acctVector);
ostream& operator << (ostream &out, Bank &tempBank);
#endif
