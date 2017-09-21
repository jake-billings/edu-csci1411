/**
 * Name: Jake Billings
 * Class: CSCI1411-004
 * Description: The implementation file for Functions.h for lab05; see billingsjLab05.cpp for program description
 * Status: Successfully compiled and run on csegrid
 */

//Include the header file
#include "Functions.h"

/**
 * rollDice returns a random member of the set that results from the intersection of (0, sides] on the
 * real numbers and integer set.
 * 
 * Returns int representing a random integer in the interval (0, sides]
 */
int rollDice (int sides) {
    return rand() % sides + 1;
}
