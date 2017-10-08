/**
 * Name: Jake Billings
 * Class CSCI 1411-004
 * Lab Partner: Matt
 *
 * Description: This is the functions file for lab05. See billinsjlab05.cpp for program description.
 * Status: Successfully compiled and run on csegrid
 */

//Guard against function redefinition
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * playGame returns an integer in the set {1. 2} representing to winner of a a game in which players take
 * turns rolling dice. A goal number is selected and passed to playGame(). playGame() then asks the user
 * for the number of faces to have on the dice for the remainder of the game. Then the players take turns
 * rolling dice until one accumlates a total score of the goal or exceeds it. If a player exceeds it
 * they lose and the other player wins.
 */
unsigned int playGame(unsigned int goal);

/**
 * rollDice returns a random member of the set that results from the intersection of (0, sides] on the
 * real numbers and integer set.
 *
 * Returns int representing a random integer in the interval (0, sides]
 */
unsigned int rollDice(unsigned int sides);

//Stop guarding
#endif

