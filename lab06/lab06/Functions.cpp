/**
 * Name: Jake Billings
 * Class: CSCI 1411-001
 * Description: Function implementation file for Lab06 (see billingsjlab06.cpp for program description)
 */

//Include cout
#include <iostream>

//Include ifstream
#include <fstream>

//Include Functions.h
#include "Functions.h"

//Use the standard namespace
using namespace std;

/**
 * Prints an error message for when a user enters an invalid selection
 */
void handleUnknownInput() {
    cout << "Sorry. I don't know how to handle that option. Please pick from the menu." << endl;
}

/**
 * Reads responses from file into memory
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
void readResponsesFromFile(Response* responses, unsigned int* responseCount, const unsigned int maxResponses) {
    //Initialize an input stream pointed at the input file
    ifstream input;
    input.open("responses.bin");

    //Initialize a counter to track how many responses we read
    unsigned int count = 0;

    //Read the responses until we reach the end of the file or fill up the allocated memory.
    while (input.peek()!=EOF && (*responseCount < maxResponses)) {
        //Initialize a local copy of the response
        Response r;

        //Read into the local copy
        getline(input, r.text);
        getline(input, r.type);

        //Store the copy in the array
        responses[*responseCount] = r;

        //Increment the counter
        count++;
        *responseCount = *responseCount+1;
    }

    //If the array is full, warn the user that it's full and it's possible not all responses loaded.
    if (*responseCount >= maxResponses) {
        cout << "Warning: the response array is full. There is no guarantee all responses were loaded." << endl;
    }

    //Print a message stating we loaded the responses
    cout << endl << "Loaded "<< count << " responses. There are now " << *responseCount << " total responses." << endl;
}

/**
 * Executes one round of magic eight ball
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
void playGame(Response* responses, unsigned int* responseCount, const unsigned int maxResponses) {
    //Abort if there are no responses.
    if (*responseCount<1) {
        cout << "There are no responses, so it is impossible to play the game." << endl;
        return;
    }

    //Pick a random response
    unsigned int responseIndex = rand() % *responseCount;

    //Print the response
    cout << responses[responseIndex].text << endl;
}

/**
 * Adds one response for the magic eight ball
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
void addResponse(Response* responses, unsigned int* responseCount, const unsigned int maxResponses) {
    //Allocate a local variable to store incoming data
    Response r;

    //Get inputs from user
    cout << "What is the text of the response you would like to add?" << endl;
    cin >> r.text;
    cout << "What is the type of the response you would like to add?" << endl;
    cin >> r.type;

    //Validate the type
    while (!(r.type=="vague"||r.type=="positive"||r.type=="negative")) {
        cout << "Sorry. You must pick vague, positive, or negative." << endl;
        cin >> r.type;
    }

    //Append it to the array
    responses[*responseCount] = r;
    *responseCount = *responseCount + 1;
}

/**
 * Executes one iteration of the menu loop.
 * 
 * Returns a boolean value that is true if the program should continue execution.
 */
bool menuIteration(Response* responses, unsigned int* responseCount, const unsigned int maxResponses) {
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
	char inputSelection = tolower(inputSelectionRaw);

	//Run the correct function based on the selection
	switch (inputSelection) {
	    case 'a':
            readResponsesFromFile(responses, responseCount, maxResponses);
            break;
	    case 'b':
            playGame(responses, responseCount, maxResponses);
            break;
	    case 'c':
            addResponse(responses, responseCount, maxResponses);
            break;
        case 'g':
            return false;
        default:
            handleUnknownInput();
	}

    return true;
}