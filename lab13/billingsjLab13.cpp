/**
 * Name: Jake Billings
 * Date: 11/30/2017
 * Class: CSCI 1411-001
 * Description: declare an array of 2 Scores, read in the 2 sets of 3 scores, Go through the array, call the .average()
 * member function for each set, and print the 3 values and the average for each set.
 * Status: compiles and runs on VS, Clion, and csegrid
 */

//---------Dependency Imports---------
//Include cout
#include <iostream>

//Include vectores
#include <vector>

//Include the Scores class
#include "Scores.h"

//Include functions
#include "functions.h"

//Use the standard namespace
using namespace std;


//---------Declare Constants---------
#define SCORES_COUNT 2

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Declare a dynamically-sized vector
    vector<Scores> scoresList;

    //Print a welcome message
    cout << "Welcome to the quiz score database." << endl;

    //Iterate once for each space in the scores object array
    for (unsigned int i = 0; i<SCORES_COUNT; i++) {
        //Print a message telling the user which object the scores are going into.
        // Add one so that humans don't get confused by our zero indexing
        cout << "We are now entering scores for student " << i + 1 << endl;

        //Read score one
        double scoreOne;
        cout << "What is score one for student " << i + 1 << "?" << endl;
        cin >> scoreOne;

        //Read score two
        double scoreTwo;
        cout << "What is score two for student " << i + 1 << "?" << endl;
        cin >> scoreTwo;

        //Read score three
        double scoreThree;
        cout << "What is score three for student " << i + 1 << "?" << endl;
        cin >> scoreThree;

        //Create the Scores object
        Scores scores(scoreOne, scoreTwo, scoreThree);

        //Place the object in the array
        scoresList.push_back(scores);
    }

    //Print a message stating we are entering the averaging-phase of the progam
    cout << "Here are the scores for each Scores object." << endl;

    //Iterate through the array again to print the averages
    for (unsigned int i = 0; i<scoresList.size(); i++) {
        cout << scoresList[i] << endl;
    }
}