/**
 * Name: Jake Billings
 * Date: 08/02/2017
 * Class: CSCI 1411-001
 * Description: Function implementations for the car dealership functions
 * Status: compiles and runs on VS, Clion, and csegrid
 */
//Include cout, cin, fileout, filein, and function headers
/**
 * Implement the user interface loop for the menu system. Called my main() in main.cpp
 *
 * @param inventory - A vector reference to the inventory we are managing
 * @return bool - False if the program should exit. True for another loop.
 */
    //Print menu
    //Read the user's choice
    //Select the correct function for a given choice
/**
 * Implement the display inventory function
 *
 * @param inventory The inventory we are managing
 */
    //If there aren't any vehicles, tell the user.
    //Print vehicle information for each vehicle
/**
 * Implement the add inventory function
 *
 * @param inventory The inventory we are managing
 */
    //Create an empty vehicle
    // Use the >> operator to read the vehicle from cin
    //Append the vehicle to the inventory
    //Notify the user of our success
/**
 * Implement the update inventory function
 *
 * @param inventory The inventory we are managing
 */
    //First, display the inventory
    //Ask the user which vehicle they want to edit
    //Tell the user we're starting
    //Take the new info
    //Tell the user we updated
/**
 * Implement the delete inventory function
 *
 * @param inventory The inventory we are managing
 */
    //First, display the inventory
    //Have the user pick a vehicle
    //Erase the vehicle by id
    //Tell the user what we did
/**
 * Implement the sort inventory function
 *
 * @param inventory The inventory we are managing
 */
    //Using bubble sort, arrange Vehicle from tallest to shortest in the inventory vector.
    //Tell the user we're done
/**
 * Implement the search inventory function
 *
 * @param inventory The inventory we are managing
 */
    //Ask the user what model to search for
    //Iterate through the inventory and add matches to a new vector
    //If no results are found, tell the user. If they are, print them out.
/**
 * Implement the read inventory from file function
 *
 * @param inventory The inventory we are managing
 */
    //Open a file input stream
    //Keep count
    //Until we reach the end of the file, deserialize vehicles and add them to inventory
    //Tell the user we're done
/**
 * Implement the write inventory to file function
 *
 * @param inventory The inventory we are managing
 */
    //Open an output stream
    //For each vehicle, write it to the file
    //Flush the output
    //Close the output stream
    //Tell the user we're done
/**
 * Implement the unknown option function
 *
 * @param inventory The inventory we are managing
 */
    //Print a message stating we don't know the option
