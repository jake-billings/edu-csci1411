/**
 * Name: Jake Billings
 * Class: CSCI 1411-001
 * Description: Function implementation file for Lab06 (see billingsjlab06.cpp for program description)
 */

//Include cout
#include<iostream>

//Use the standard namespace
using namespace std;

/**
 * Executes one iteration of the menu loop.
 * 
 * Returns a boolean value that is true if the program should continue execution.
 */
bool menuIteration() {
	//Print the menu options.
	cout << "Please select one of the following using the letter." << endl;
	cout << "a.\tRead responses from a file" << endl;
	cout << "b.\tPlay Magic Eight Ball" << endl;
	cout << "c.\tAdd responses to a file" << endl;
	cout << "d.\tPrint out responses alphabetically" << endl;
	cout << "e.\tPrint out responses by type(positive, negative, vague)" << endl;
	cout << "f.\tWrite responses to a file" << endl;
	cout << "g.\tExit" << endl;

	//Allocate a space in memory for the user's answer
	char inputSelectionRaw;
	cout << "Which option would you like to select?" << endl;
	cin >> inputSelectionRaw;

	//Convert the selection to lowercase
	char inputSelection = tolower(inputSelection);

	//Run the correct function based on the selection
	switch (inputSelection) {
	case 'a':
		cout << "Case a" << endl;
	}
}