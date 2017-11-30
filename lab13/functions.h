/**
 * Name: Jake Billings
 * Date: 11/30/2017
 * Class: CSCI 1411-001
 * Description: Function definitions for lab13
 * Status: compiles and runs on VS, Clion, and csegrid
 */

//---------Dependency Imports---------
//Include cout
#include <iostream>

//Include vectors
#include <vector>

//Include the Scores class
#include "Scores.h"

//Use the standard namespace
using namespace std;

//---------Declarations------------
/**
 * Declare << Operator for Scores object
 *
 * Prints the three scores and the average of them to an output stream.
 *
 * @param out An output stream to print to; usually cout
 * @param scores The scores object to print
 * @return Returns the out object
 */
ostream& operator << (ostream &out, Scores &scores);

/**
 * Declare bubbleSort for vectors of Scores objects
 *
 * Performs an in-place ascending bubbleSort on a vector of Scores objects using the
 * average score as a sort predicate.
 *
 * @param scoresVector
 */
void bubbleSort(vector<Scores> scoresVector);