/**
 * Name: Jake Billings
 * Date: 10/26/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	char* cstring = "C string";
	char* reverse;
	const int size = 9;
	string mystring = "string", reverseString;


	cout << "cstring:" << endl;
	printCString(cstring, size);
	reverse = backwardCString(cstring, size);
	printCString(reverse, size);

	cout << endl << "string:" << endl;
	cout << mystring << endl;
	reverseString = backwardString(mystring);
	cout << reverseString << endl;


	return 0;
}
