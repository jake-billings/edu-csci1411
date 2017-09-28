/**
 * Name: Jake Billings
 * Class: CSCI1411-004
 * Description: The "Additional Skills" section of lab06
 * Status: Successfully compiled and run on Visual Studio
 */


//Include cout
#include <iostream>

//Include rand()
#include <stdlib.h>

//Include time()
#include <time.h>

//Use the standard namespace
using namespace std;

int main() {
    //Seed the random number generator using the current time from time()
    srand(time(NULL));

    //Allocate local variables to store user input
    unsigned int inputNumberCount, inputNumberMax;


    //Acquire the user input necessary for the program
    cout << "How many numbers should I generate?" << endl;
    cin >> inputNumberCount;

    cout << "What's the maximum value a number should be" << endl;
    cin >> inputNumberMax;

    //Allocate an array to store the randomly generated numbers
    unsigned int randomNumbers[inputNumberCount];

    //Generate a random number
    for (unsigned int i = 0; i < inputNumberCount; i++) {
        //Return a random in the range by getting a random number in (0, MAX_RAND) and take the modulus to get it on the
        // range (0, inputNumberMax)
        randomNumbers[i] = rand() % inputNumberMax;
    }
}