/**
 * Name: Jake Billings
 * Class: CSCI1411-004
 * Description: The implementation file for Functions.h for lab05; see billingsjLab05.cpp for program description
 * Status: Successfully compiled and run on csegrid
 */

//Include the header file
#include "Functions.h"

//Include cout
#include <iostream>

//Include rand()
#include <stdlib.h>

//Include time()
#include <time.h>

//Use the standard namespace
using namespace std;


/**
 * playGame returns an integer in the set {1. 2} representing to winner of a a game in which players take
 * turns rolling dice. A goal number is selected and passed to playGame(). playGame() then asks the user
 * for the number of faces to have on the dice for the remainder of the game. Then the players take turns
 * rolling dice until one accumlates a total score of the goal or exceeds it. If a player exceeds it
 * they lose and the other player wins.
 */
unsigned int playGame(unsigned int goal) {
    //Print a starting  message for the game containing the goal
    cout << "Starting game with a goal of " << goal << "." << endl;
    
    //Allocate a space in locally-scoped memory for the number of faces that should be on dice.
    unsigned int inputFaceCount;
    
    //Ask the user how many faces they want on their dice
    cout << "How many faces should be on the dice?" << endl;
    cin >> inputFaceCount;
    
    //Seed the random number generator using the current time from time()
    srand(time(NULL));
     
    //Allocate a space in memory for each player's score.
    unsigned int scorePlayer1 = 0;
    unsigned int scorePlayer2 = 0;
    
    //Allocate a space in memory to store the winning player for purposes of iteration.
    // The while loop will terminate once a winner is found. Winner is instatiated as 0.
    // A value of 0 means that no player has been found.
    unsigned int winner = 0;
    
    //Instantiate a variable to store the currently active player. This matters when running the round.
    // The value of activePlayer should alternate between 1 and 2 on each iteration of the while loop 
    // (each round)
    unsigned int activePlayer = 1;
    
    //Iterate until a winner is found (inside the while block is one round)
    while (!winner) {
        //Use the rollDice() function to roll a die with the number of faces from 
        unsigned int roll = rollDice(inputFaceCount);
        
        //Print what a player rolled and what his/her new score is
        cout << "Player " << activePlayer << " rolled " << roll << " and now has a score of ";
        
        //Execute different branches based on the active player
        // Add the roll to the active player's score. If the active player's
        // score is now greater than the goal, the other player wins. If it's
        // equal to the goal, the active player wins. Otherwise, no player has
        // won yet and another round must execute.
        if (activePlayer==1) {
            scorePlayer1 += roll;
            
            //Log the new score.
            cout << scorePlayer1;
            
            if (scorePlayer1>goal) {
                winner = 2;
            } else if (scorePlayer2==goal) {
                winner = 1;
            }
        } else {
            scorePlayer2 += roll;
            
            //Log the new score.
            cout << scorePlayer2;
            
            if (scorePlayer2>goal) {
                winner = 1;
            } else if (scorePlayer2==goal) {
                winner = 2;
            }
        }
        
        cout << "." << endl;
               
        //Alternate the player every round
        activePlayer = activePlayer==1?2:1;
    }
    
    //Return the winner as the result of the function
    return winner;
}


/**
 * rollDice returns a random member of the set that results from the intersection of (0, sides] on the
 * real numbers and integer set.
 * 
 * Returns int representing a random integer in the interval (0, sides]
 */
unsigned int rollDice (unsigned int sides) {
    //Return a random in the range by getting a random number in (0, MAX_RAND) and take the modulus then add 1
    return rand() % sides + 1;
}
