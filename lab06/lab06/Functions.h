/**
 * Name: Jake Billings
 * Class: CSCI 1411-001
 * Description: Header file for Functions.cpp (See billingsjLab06.cpp for program description and Functions.cpp for implementation)
 * Status: compiles and runs on VS, Clion, and csegrid
 */

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
 * Prints an error message for when a user enters an invalid selection
 */
void handleUnknownInput();


/**
 * Reads responses from file into memory
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
void readResponsesFromFile(Response* responses, unsigned int* responseCount, const unsigned int maxResponses);


/**
 * Executes one round of magic eight ball
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void playGame(Response* responses, unsigned int* responseCount);


/**
 * Adds one response for the magic eight ball
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
void addResponse(Response* responses, unsigned int* responseCount, const unsigned int maxResponses);


/**
 * Prints all responses in the responses array
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponses(Response* responses, unsigned int* responseCount);


/**
 * Prints all responses in the responses array alphabetically by alphabetizing the array by text in memory then printing it
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponsesAlphabetically(Response* responses, unsigned int* responseCount);

/**
 * Prints all responses in the responses array alphabetically by alphabetizing the array by type in memory then printing it
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponsesByType(Response* responses, unsigned int* responseCount);


/**
 * Writes all responses in the responses array to a file
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 */
void writeResponsesToFile(Response* responses, unsigned int* responseCount);


/**
 * Executes one iteration of the menu loop.
 *
 * Returns a boolean value that is true if the program should continue execution.
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
bool menuIteration(Response* responses, unsigned int* responseCount, const unsigned int maxResponses);

#endif //EDU_CSCI1411_FUNCTIONS_H
