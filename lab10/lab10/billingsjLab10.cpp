/**
 * Name: Jake Billings
 * Date: 10/19/2017
 * Class: CSCI 1411-001
 * Description: Accepts a variable number of test scores as input and provides the ability to sort,
 *  average, and list them.
 * Status: compiles and runs on VS, Clion, and csegrid
 */


//---------Dependency Imports---------
//Include cout
#include <iostream>

//Include strings
#include <string>

//Use the standard namespace
using namespace std;

//-------Function Declarations--------
void displayBackwards(const char *cstring) {
    //Count the characters in the string
    unsigned int length = 0;
    for (unsigned int i = 0; cstring[i] != '\0'; i++) {
        length++;
    }
    for (int i = length-1; i >= 0; i--) {
        cout << cstring[i];
    }
    cout << endl;
}

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Print a welcoming message to great our users
    cout << "Welcome to C-String Reverse." << endl;

    //Ask the user what string they would like to reverse
    cout << "What string would you like to reverse?" << endl;

    //Load a cstring from user input
    string input;
    const char *cstring;
    getline(cin, input);
    cstring = input.c_str();

    //Display the string backwards
    displayBackwards(cstring);
}