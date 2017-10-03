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
    //Find out what file to read from
    string filePath;
    cout << "What file would you like to read from? (The default responses are in \"responses.bin\".)" << endl;
    cin.ignore(); //Ignore since we're using getline()
    getline(cin, filePath);

    //Default to responses.bin
    if (filePath=="") {
        cout << "Defaulting to \"responses.bin\"." << endl;
        filePath = "responses.bin";
    }

    //Initialize an input stream pointed at the input file
    ifstream input;
    input.open(filePath);

    //Initialize a counter to track how many responses we read
    unsigned int count = 0;

    //Read the responses until we reach the end of the file or fill up the allocated memory.
    while (input.peek() != EOF && (*responseCount < maxResponses)) {
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

    //Close the input stream
    input.close();

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
 */
void playGame(Response* responses, unsigned int* responseCount) {
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
    //If we've exceeded available memory, print an error message and prevent response creation.
    if (*responseCount >= maxResponses) {
        cout << "Sorry. I can't crate a new response because the response array is full." << endl;
        return;
    }

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
 * Prints all responses in the responses array
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponses(Response* responses, unsigned int* responseCount) {
    //Iterate through each response index (0, responseCount)
    for (unsigned int i = 0; i < *responseCount; i++) {
        //Print the response
        cout << "Response " << i << ": " << responses[i].text << " (" << responses[i].type << ")" << endl;
    }
}


/**
 * Prints all responses in the responses array alphabetically by alphabetizing the array by text in memory then printing it
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponsesAlphabetically(Response* responses, unsigned int* responseCount) {
    //Sort the responses in memory using bubble sort by text
    //Perform a double iteration over the array
    for (unsigned long i = 0; i < *responseCount; i++) {
        for (unsigned long j = 0; j+1 < *responseCount; j++) {
            //Cache the response at index j
            Response r = responses[j];

            //Compare the alphabetical index of responses[j] and responses[j+1] using the > operator
            if (r.text > responses[j+1].text) {

                //Swap the responses if they are in the wrong order
                responses[j] = responses[j+1];
                responses[j+1] = r;
            }
        }
    }

    //Print the responses in the order they're in in memory, which is now alphabetical
    printResponses(responses, responseCount);
}

/**
 * Prints all responses in the responses array alphabetically by alphabetizing the array by type in memory then printing it
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponsesByType(Response* responses, unsigned int* responseCount) {
    //Sort the responses in memory using bubble sort by type
    //Perform a double iteration over the array
    for (unsigned long i = 0; i < *responseCount; i++) {
        for (unsigned long j = 0; j+1 < *responseCount; j++) {
            //Cache the response at index j
            Response r = responses[j];

            //Compare the alphabetical index of responses[j] and responses[j+1] using the > operator
            if (r.type > responses[j+1].type) {

                //Swap the responses if they are in the wrong order
                responses[j] = responses[j+1];
                responses[j+1] = r;
            }
        }
    }

    //Print the responses in the order they're in in memory, which is now alphabetical
    printResponses(responses, responseCount);
}


/**
 * Writes all responses in the responses array to a file
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 */
void writeResponsesToFile(Response* responses, unsigned int* responseCount) {
    //Find out what file to read from
    string filePath;
    cout << "What file would you like to write to? (I recommend ending this file in \".bin\" for consistency.)" << endl;
    cin.ignore(); //Ignore since we're using getline()
    getline(cin, filePath);

    //Open an output stream to a file
    ofstream output;
    output.open(filePath);

    //For each response, write it to the output stream in the same format as the input file
    for (unsigned long i = 0; i < *responseCount; i++) {
        output << responses[i].text << endl;
        output << responses[i].type << endl;
    }

    //Close the output stream
    output.close();
}


/**
 * Deletes a response from the response array
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 */
void removeResponse(Response* responses, unsigned int* responseCount) {
    //Allocate a local variable and get user input for which response to delete
    unsigned int targetIndex;
    cout << "Which response would you like to delete (pick by index)?" << endl;
    cin >> targetIndex;

    //Validate the target index
    while (targetIndex >= *responseCount) {
        cout << "Sorry. Please pick an index that exists in the response array." << endl;
        cin >> targetIndex;
    }

    //Move the array data left in order to overwrite the deleted element and shift all the
    // memory elements left
    // Start at the source, which is the response after the target of deleting
    // Move the data starting at this source to the location of the target overwriting it in the process
    // Stop once you've copied the number of bytes equal to the all of the data in the array
    memmove(responses+targetIndex,
            responses+(targetIndex+1),
            (*responseCount-targetIndex-1)*sizeof(Response));

    //Update the responseCount variable to reflect the shift
    *responseCount = *responseCount - 1;
}


/**
 * Executes one iteration of the menu loop.
 * 
 * Returns a boolean value that is true if the program should continue execution.
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
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
    cout << "h.\tDelete response (Extra Credit)" << endl;

	//Allocate a space in memory for the user's answer and read it using cin
	char inputSelectionRaw;
	cout << "Which option would you like to select?" << endl;
	cin >> inputSelectionRaw;

	//Convert the selection to lowercase for easier switch cases
	char inputSelection = tolower(inputSelectionRaw);

	//Run the correct function based on the selection
	switch (inputSelection) {
	    case 'a':
            readResponsesFromFile(responses, responseCount, maxResponses);
            break;
	    case 'b':
            playGame(responses, responseCount);
            break;
	    case 'c':
            addResponse(responses, responseCount, maxResponses);
            break;
	    case 'd':
            printResponsesAlphabetically(responses, responseCount);
            break;
	    case 'e':
            printResponsesByType(responses, responseCount);
            break;
	    case 'f':
            writeResponsesToFile(responses, responseCount);
            break;
        case 'g':
            return false;
        case 'h':
            removeResponse(responses, responseCount);
            break;
        default:
            handleUnknownInput();
	}

    //Return true because we want to complete the loop again
    // We would have returned false if we didn't.
    return true;
}