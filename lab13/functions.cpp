/**
 * Name: Jake Billings
 * Date: 11/30/2017
 * Class: CSCI 1411-001
 * Description: Function implementations for lab13
 * Status: compiles and runs on VS, Clion, and csegrid
 */

//Include the functions header, which includes dependencies
#include "functions.h"

//---------Implementations------------
/**
 * Implement << Operator for Scores object
 *
 * Prints the three scores and the average of them to an output stream.
 *
 * @param out An output stream to print to; usually cout
 * @param scores The scores object to print
 * @return Returns the out object
 */
ostream& operator << (ostream &out, Scores &scores) {
    //Write to the output stream
    out << "Score One:\t" << scores.getScoreOne() << endl;
    out << "Score Two:\t" << scores.getScoreTwo() << endl;
    out << "Score Three:\t" << scores.getScoreThree() << endl;
    out << "Average:\t" << scores.getAverage() << endl;

    //Return the output stream
    return out;
}

/**
 * Implement bubbleSort() for vectors of Scores objects.
 *
 * Performs an in-place ascending bubbleSort on a vector of Scores objects using the
 * average score as a sort predicate.
 *
 * @param scoresVector
 */
void bubbleSort(vector<Scores>& scoresVector) {
    //Using bubble sort, arrange Scores from tallest to shortest in the inventory vector.
    for (unsigned long i = 0; i<scoresVector.size(); i++) {
        for (unsigned long j = 0; j<scoresVector.size()-1; j++) {
            Scores v = scoresVector[j];
            if (v.getAverage() > scoresVector[j+1].getAverage()) {
                scoresVector[j] = scoresVector[j+1];
                scoresVector[j+1] = v;
            }
        }
    }
}
