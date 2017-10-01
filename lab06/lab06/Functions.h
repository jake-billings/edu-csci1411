//
// Created by Jake Billings on 9/29/17.
//

#ifndef EDU_CSCI1411_FUNCTIONS_H
#define EDU_CSCI1411_FUNCTIONS_H

#include <string>

using namespace std;

/**
 * Response struct defines the structure for each magic 8 ball response
 */
struct Response {
    /**
     * The text of the response
     */
    string text;

    /**
     * Integer representing if the answer is
     * vague, positive or negative.
     */
    string type;
};

/**
 * Executes one iteration of the menu loop.
 *
 * Returns a boolean value that is true if the program should continue execution.
 */
bool menuIteration(Response* responses, unsigned int* responseCount, const unsigned int maxResponses);

#endif //EDU_CSCI1411_FUNCTIONS_H
