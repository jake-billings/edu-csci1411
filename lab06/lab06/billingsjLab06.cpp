/**
 * Name: Jake Billings
 * Class: CSCI 1411-001
 * Description: CSCI1410_PA2: Magic Eight Ball. This program is a full-featured
 * customizable digital magic eight ball.
 */

//Include Functions
#include "Functions.h"

//Include cout
#include <iostream>

//Include srand
#include <stdlib.h>

//Use the standard namespace
using namespace std;

/**
 * main() Prints goodbye/welcome messages and iterates the menu function
 *
 * @return int 0 - Nothing went wrong
 */
int main() {
    //Seed the random number generator
    srand(time(0));

    //Set a cap on the number of responses we can store that is way bigger than we would ever need
    const unsigned int maxResponses = 1024;

    //Keep track of how many responses are in our array
    unsigned int responseCount = 0;

    //Allocate an array in memory to store our potential responses that is far bigger than
    // we would ever need.
    Response* responses = (Response*) malloc(sizeof(Response)*maxResponses);

    //Print a welcome message
    cout << "Welcome to Magic 8 Ball." << endl;

    //Keep executing the menu iteration function until it returns false.
    while (menuIteration(responses, &responseCount, maxResponses));

    //Print a goodbye message
    cout << "Goodbye." << endl;

    //Return status code 0 because nothing went wrong.
    return 0;
}