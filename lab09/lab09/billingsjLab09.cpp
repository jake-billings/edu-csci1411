/**
 * Name: Jake Billings
 * Date: 10/19/2017
 * Class: CSCI 1411-001
 * Description: Accepts a variable number of test scores as input and provides the ability to sort,
 *  average, and list them.
 * Status: compiles and runs on VS, Clion, and csegrid
 */


//---------Dependency Imports---------
//Include cout
#include <iostream>

//Use the standard namespace
using namespace std;


/**
 * Add a score to the array
 *
 *
 * @param scores The array of scores to read into
 * @param scoresCount The number of scores already in that array
 * @param maxScores The maximum number of scores allowed in the scores array
 */
void addScore(uint8_t* scores, unsigned int* scoreCount, unsigned int maxScores) {
    //Don't let the user add to the array if it's full.
    if (*scoreCount >= maxScores) {
        cout << "Sorry. The scores array is full. Allocate with more space next time." << endl;

        return;
    }

    //Collect the new score
    cout << "What is the new score?" << endl;
    int score;
    cin >> score;

    //Validate and cast the new score
    if (score < 0) {
        cout << "Sorry. I can't add a negative score. It doesn't make any sense." << endl;
        return;
    }
    if (score > 100) {
        cout << "Sorry. I can't add a score greater than 100. That doesn't make any sense." << endl;
        return;
    }

    //Cast the score to the more efficient 8-bit data type
    auto score_8 = (uint8_t) score;

    //Put the score into the last slot in the array
    scores[*scoreCount] = score_8;

    //Increment the array size
    *scoreCount = *scoreCount + 1;

    //Confirm the addition
    cout << "Score added." << endl;
}


/**
 * Sorts all scores in the scores array in memory
 *
 * @param scores The array of scores to read into
 * @param scoresCount The number of scores already in that array
 */
void sortScores(uint8_t* scores, unsigned int* scoreCount) {
    //Sort the movies in memory using bubble sort by type
    //Perform a double iteration over the array
    for (unsigned long i = 0; i < *scoreCount; i++) {
        for (unsigned long j = 0; j+1 < *scoreCount; j++) {
            //Cache the movie at index j
            uint8_t s = scores[j];

            //Compare the scores of scores[j] and scores[j+1] using the > operator
            if (s > scores[j+1]) {

                //Swap the scores if they are in the wrong order
                scores[j] = scores[j+1];
                scores[j+1] = s;
            }
        }
    }
}


/**
 * Prints all scores in the scores array
 *
 * @param scores The array of responses to read into
 * @param scoreCount The number of responses already in that array
 */
void printScores(uint8_t* scores, unsigned int* scoreCount) {
    //Print a message if there are no scores
    if (*scoreCount < 1) {
        cout << "Currently, there are no scores in the database." << endl;
    }

    //Iterate through each score index (0, responseCount)
    for (unsigned int i = 0; i < *scoreCount; i++) {
        //Print the response
        cout << "Score " << i << ": " << (int) scores[i] << endl;
    }
}


/**
 * Calculates the average of all scores in the scores array and prints it
 *
 * @param scores The array of responses to read into
 * @param scoreCount The number of responses already in that array
 */
void printAverageScore(uint8_t* scores, unsigned int* scoreCount) {
    //Print a message if there are no scores
    if (*scoreCount < 1) {
        cout << "Currently, there are no scores in the database." << endl;
        return;
    }

    //Allocate and initialize a place in memory for the sum
    unsigned int sum = 0;

    //Iterate through each score index (0, responseCount)
    for (unsigned int i = 0; i < *scoreCount; i++) {
        //Add to the sum
        sum += scores[i];
    }

    //Calculate the average from the sum and count
    double average = ((double) sum) / ((double) *scoreCount);

    //Print the average
    cout << "The average score is " << average << "." << endl;
}


/**
 * Prints an error message for when a user enters an invalid selection
 */
void handleUnknownInput() {
    cout << "Sorry. I don't know how to handle that option. Please pick from the menu." << endl;
}


/**
 * Executes one iteration of the menu loop.
 *
 * Returns a boolean value that is true if the program should continue execution.
 *
 * @param scores The array of scores to read out of
 * @param movieCount The number of scores already in that array
 * @param maxScores The maximum number of scores that can fit in the array
 */
bool menuIteration(uint8_t* scores, unsigned int* scoreCount, unsigned int maxScores) {
    //Print the menu options.
    cout << "Please select one of the following using the letter." << endl;
    cout << "1.\tAdd Score" << endl;
    cout << "2.\tSort Scores" << endl;
    cout << "3.\tList Scores" << endl;
    cout << "4.\tCalculate Average Score" << endl;
    cout << "0.\tExit" << endl;

    //Allocate a space in memory for the user's answer and read it using cin
    int inputSelection;
    cout << "Which option would you like to select?" << endl;
    cin >> inputSelection;

    //Run the correct function based on the selection
    switch (inputSelection) {
        case 1:
            addScore(scores, scoreCount, maxScores);
            break;
        case 2:
            sortScores(scores, scoreCount);
            break;
        case 3:
            printScores(scores, scoreCount);
            break;
        case 4:
            printAverageScore(scores, scoreCount);
            break;
        case 0:
            return false;
        default:
            handleUnknownInput();
    }

    cout << endl;

    //Return true because we want to complete the loop again
    // We would have returned false if we didn't.
    return true;
}


//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Store the maximum number of test scores we are expecting to see
    unsigned int maxScores;
    cout << "How many test scores do you need to score?" << endl;
    cin >> maxScores;

    //Allocate an integer to track the number of scores in the score list
    unsigned int scoreCount = 0;

    //Use malloc() to allocate an array to store the incoming test scores.
    auto* scores = (uint8_t*) malloc(sizeof(uint8_t)*maxScores);

    //Print a welcome message
    cout << "Welcome to the Local Test Score Database." << endl;

    //Keep executing the menu iteration function until it returns false.
    while (menuIteration(scores, &scoreCount, maxScores));

    //Print a goodbye message
    cout << "Goodbye." << endl;
}