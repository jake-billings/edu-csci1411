/**
 * Name: Jake Billings
 * Class: CSCI1411-004
 * Description: A simple 2-player game to exemplify the use of functions and random numbers. See playGame() in 
 * functions.cpp() to see the rules of the game.
 * Lab Partner: Matt
 */

//Include the functions necessary to run this game.
#include "Functions.h"
//Include iostream functions
#include <iostream>

//Use the standard namespace
using namespace std;

//Declare the main() function
int main() {
    //Print a welcome message so users know that they came to the right program.
    cout << "Welcome to the game. Let's find out who wins..." << endl;
    
    //Allocate a space in memory to store the goal
    unsigned int goal;

    //Ask the user what the goal is
    cout << "What is the goal score for this game?" << endl;
    cin >> goal;
    
    //Call the playGame() function to figure out who wins.
    int winningPlayer = playGame(goal);
    
    //Print the winning player to the console
    cout << "Player " << winningPlayer << " won!" << endl;
    
    //Return the 0 status code to indicate the program completed successfully.
    return 0;
}

