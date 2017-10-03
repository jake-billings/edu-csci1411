/**
 * Name: Jake Billings
 * Class: CSCI 1411-001
 * Description: Function implementation file for Lab06 (see billingsjlab06.cpp for program description)
 * Status: compiles and runs on VS, Clion, and csegrid
 */
//Include cout
//Include ifstream
//Include Functions.h
//Use the standard namespace
/**
 * Prints an error message for when a user enters an invalid selection
 */
/**
 * Reads responses from file into memory
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
void readResponsesFromFile(Response* responses, unsigned int* responseCount, const unsigned int maxResponses) {
    //Find out what file to read from
    cin.ignore(); //Ignore since we're using getline()
    //Default to responses.bin
    //Initialize an input stream pointed at the input file
    //Initialize a counter to track how many responses we read
    //Read the responses until we reach the end of the file or fill up the allocated memory.
    while (input.peek() != EOF && (*responseCount < maxResponses)) {
        //Initialize a local copy of the response
        //Read into the local copy
        //Store the copy in the array
        responses[*responseCount] = r;
        //Increment the counter
        *responseCount = *responseCount+1;
    //Close the input stream
    //If the array is full, warn the user that it's full and it's possible not all responses loaded.
    if (*responseCount >= maxResponses) {
    //Print a message stating we loaded the responses
    cout << endl << "Loaded "<< count << " responses. There are now " << *responseCount << " total responses." << endl;
/**
 * Executes one round of magic eight ball
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void playGame(Response* responses, unsigned int* responseCount) {
    //Abort if there are no responses.
    if (*responseCount<1) {
    //Pick a random response
    unsigned int responseIndex = rand() % *responseCount;
    //Print the response
/**
 * Adds one response for the magic eight ball
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
void addResponse(Response* responses, unsigned int* responseCount, const unsigned int maxResponses) {
    //If we've exceeded available memory, print an error message and prevent response creation.
    if (*responseCount >= maxResponses) {
    //Allocate a local variable to store incoming data
    //Get inputs from user
    //Validate the type
    //Append it to the array
    responses[*responseCount] = r;
    *responseCount = *responseCount + 1;
/**
 * Prints all responses in the responses array
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponses(Response* responses, unsigned int* responseCount) {
    //Iterate through each response index (0, responseCount)
    for (unsigned int i = 0; i < *responseCount; i++) {
        //Print the response
/**
 * Prints all responses in the responses array alphabetically by alphabetizing the array by text in memory then printing it
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponsesAlphabetically(Response* responses, unsigned int* responseCount) {
    //Sort the responses in memory using bubble sort by text
    //Perform a double iteration over the array
    for (unsigned long i = 0; i < *responseCount; i++) {
        for (unsigned long j = 0; j+1 < *responseCount; j++) {
            //Cache the response at index j
            //Compare the alphabetical index of responses[j] and responses[j+1] using the > operator
                //Swap the responses if they are in the wrong order
    //Print the responses in the order they're in in memory, which is now alphabetical
/**
 * Prints all responses in the responses array alphabetically by alphabetizing the array by type in memory then printing it
 *
 * @param responses The array of responses to read into
 * @param responseCount The number of responses already in that array
 */
void printResponsesByType(Response* responses, unsigned int* responseCount) {
    //Sort the responses in memory using bubble sort by type
    //Perform a double iteration over the array
    for (unsigned long i = 0; i < *responseCount; i++) {
        for (unsigned long j = 0; j+1 < *responseCount; j++) {
            //Cache the response at index j
            //Compare the alphabetical index of responses[j] and responses[j+1] using the > operator
                //Swap the responses if they are in the wrong order
    //Print the responses in the order they're in in memory, which is now alphabetical
/**
 * Writes all responses in the responses array to a file
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 */
void writeResponsesToFile(Response* responses, unsigned int* responseCount) {
    //Find out what file to read from
    cin.ignore(); //Ignore since we're using getline()
    //Open an output stream to a file
    //For each response, write it to the output stream in the same format as the input file
    for (unsigned long i = 0; i < *responseCount; i++) {
    //Close the output stream
/**
 * Deletes a response from the response array
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 */
void removeResponse(Response* responses, unsigned int* responseCount) {
    //Allocate a local variable and get user input for which response to delete
    //Validate the target index
    while (targetIndex >= *responseCount) {
    //Move the array data left in order to overwrite the deleted element and shift all the
    // memory elements left
    // Start at the source, which is the response after the target of deleting
    // Move the data starting at this source to the location of the target overwriting it in the process
    // Stop once you've copied the number of bytes equal to the all of the data in the array
            (*responseCount-targetIndex-1)*sizeof(Response));
    //Update the responseCount variable to reflect the shift
    *responseCount = *responseCount - 1;
/**
 * Executes one iteration of the menu loop.
 * 
 * Returns a boolean value that is true if the program should continue execution.
 *
 * @param responses The array of responses to read out of
 * @param responseCount The number of responses already in that array
 * @param maxResponses The maximum number of responses that can fit in the array
 */
bool menuIteration(Response* responses, unsigned int* responseCount, const unsigned int maxResponses) {
	//Print the menu options.
	//Allocate a space in memory for the user's answer and read it using cin
	//Convert the selection to lowercase for easier switch cases
	//Run the correct function based on the selection
    //Return true because we want to complete the loop again
    // We would have returned false if we didn't.
