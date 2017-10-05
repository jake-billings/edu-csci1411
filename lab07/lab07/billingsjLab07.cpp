/**
 * Name: Jake Billings
 * Class: CSCI 1411-001
 * Description: A program that reads movies from a file and processes the data appropriately
 * Status: compiles and runs on VS, Clion, and csegrid
 */

//---------Dependency Imports---------
//Include cout
#include <iostream>

//Include ifstream
#include <fstream>

//Use the standard namespace
using namespace std;


//-------------Data Types-------------
struct MovieData {
    string title;
    uint16_t releaseYear;
    uint16_t runningTime;
    uint8_t rating;
};


//----------Function Headers----------
void readMoviesFromFile(MovieData* movies, unsigned int* movieCount, unsigned int maxMovies);
void addMovie(MovieData* movies, unsigned int* movieCount, unsigned int maxMovies);
void printMovies(MovieData* movies, unsigned int* movieCount);


//------Function Implementations------
/**
 * Reads MovieDatas from file into memory
 *
 * @param movies The array of MovieDatas to read into
 * @param movieCount The number of MovieDatas already in that array
 * @param maxMovies The maximum number of MovieDatas that can fit in the array
 */
void readMoviesFromFile(MovieData* movies, unsigned int* movieCount, const unsigned int maxMovies) {
    //Find out what file to read from
    string filePath;
    cout << "What file would you like to read from? (The default movies are in \"data.bin\".)" << endl;
    cin.ignore(); //Ignore since we're using getline()
    getline(cin, filePath);

    //Default to movies.bin
    if (filePath=="") {
        cout << "Defaulting to \"data.bin\"." << endl;
        filePath = "data.bin";
    }

    //Initialize an input stream pointed at the input file
    ifstream input;
    input.open(filePath);

    //Initialize a counter to track how many movies we read
    unsigned int count = 0;

    //Read the movies until we reach the end of the file or fill up the allocated memory.
    while (input.peek() != EOF && (*movieCount < maxMovies)) {
        //Declare strings to read lines
        string title, releaseYear, runningTime, rating;

        //Read the lines from the file
        getline(input, title);
        getline(input, releaseYear);
        getline(input, runningTime);
        getline(input, rating);

        cout << "Loading " << title << endl;

        //Initialize a local copy of the movie
        MovieData r;

        r.title = title;
        r.releaseYear = (uint16_t) atoi(releaseYear.c_str());
        r.runningTime = (uint16_t) atoi(runningTime.c_str());
        r.rating      = (uint8_t)  atoi(rating.c_str());

        //Store the copy in the array
        movies[*movieCount] = r;

        //Increment the counter
        count++;
        *movieCount = *movieCount+1;
    }

    //Close the input stream
    input.close();

    //If the array is full, warn the user that it's full and it's possible not all movies loaded.
    if (*movieCount >= maxMovies) {
        cout << "Warning: the movie array is full. There is no guarantee all movies were loaded." << endl;
    }

    //Print a message stating we loaded the movies
    cout << endl << "Loaded "<< count << " movies. There are now " << *movieCount << " total movies." << endl;
}


/**
 * Adds one movie for the magic eight ball
 *
 * @param movies The array of movies to read into
 * @param movieCount The number of movies already in that array
 * @param maxMovies The maximum number of movies that can fit in the array
 */
void addMovie(MovieData* movies, unsigned int* movieCount, const unsigned int maxMovies) {
    //If we've exceeded available memory, print an error message and prevent movie creation.
    if (*movieCount >= maxMovies) {
        cout << "Sorry. I can't crate a new movie because the movie array is full." << endl;
        return;
    }

    //Allocate a local variable to store incoming data
    MovieData r;

    //Get inputs from user
    cout << "What is the title of the movie you would like to add?" << endl;
    cin >> r.title;
    cout << "What year was " << r.title << " released?" << endl;
    cin >> r.releaseYear;
    cout << "What was the run time of " << r.title << " in minutes?" << endl;
    cin >> r.runningTime;
    cout << "What percentage score did " << r.title << " receive on Rotten Tomatoes?" << endl;
    cin >> r.rating;

    //Append it to the array
    movies[*movieCount] = r;
    *movieCount = *movieCount + 1;
}

/**
 * Prints a specific movie to the console
 *
 * @param movie MovieData to print
 * @param index The unsigned integer index to print in the message
 */
void printMovie(MovieData movie, unsigned int index) {
    //Print the movie
    cout << "Movie " << index << ":\t\"" << movie.title << "\"\twas released " << movie.releaseYear;
    cout << ",\tran for " << movie.runningTime << " minutes,\tand received a Rotten Tomatoes";
    cout << " score of " << (int) movie.rating << "." << endl;
}


/**
 * Prints a specific movies in the movies array based on user input
 *
 * @param movies The array of movies to read into
 * @param movieCount The number of movies already in that array
 */
void printMovie(MovieData* movies, unsigned int* movieCount) {
    //If there are no movies to print, tell the user we tried
    if (*movieCount<=0) {
        cout << "There are no movies to list. Try adding some or loading a file." << endl;
    }

    //Read the index that the user would like to print
    unsigned int index;
    cout << "Which movie would you like to view (enter an integer index)?" << endl;
    cin >> index;

    //Print the movie
    printMovie(movies[index], index);
}


/**
 * Prints all movies in the movies array
 *
 * @param movies The array of movies to read into
 * @param movieCount The number of movies already in that array
 */
void printMovies(MovieData* movies, unsigned int* movieCount) {
    //If there are no movies to print, tell the user we tried
    if (*movieCount<=0) {
        cout << "There are no movies to list. Try adding some or loading a file." << endl;
    }

    //Iterate through each movie index (0, movieCount)
    for (unsigned int i = 0; i < *movieCount; i++) {
        //Print the movie
        printMovie(movies[i], i);
    }
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
 * @param movies The array of movies to read out of
 * @param movieCount The number of movies already in that array
 * @param maxMovies The maximum number of movies that can fit in the array
 */
bool menuIteration(MovieData* movies, unsigned int* movieCount, const unsigned int maxMovies) {
    //Print the menu options.
    cout << "Please select one of the following using the letter." << endl;
    cout << "1.\tRead movies from a file" << endl;
    cout << "2.\tAdd Movie" << endl;
    cout << "3.\tList Movies" << endl;
    cout << "4.\tPrint Specific Movie by Index" << endl;
    cout << "0.\tExit" << endl;

    //Allocate a space in memory for the user's answer and read it using cin
    int inputSelection;
    cout << "Which option would you like to select?" << endl;
    cin >> inputSelection;

    //Run the correct function based on the selection
    switch (inputSelection) {
        case 1:
            readMoviesFromFile(movies, movieCount, maxMovies);
            break;
        case 2:
            addMovie(movies, movieCount, maxMovies);
            break;
        case 3:
            printMovies(movies, movieCount);
            break;
        case 4:
            printMovie(movies, movieCount);
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
    //Set a cap on the number of responses we can store that is way bigger than we would ever need
    const unsigned int maxMovies = 1024;

    //Keep track of how many responses are in our array
    unsigned int movieCount = 0;

    //Allocate an array in memory to store our potential responses that is far bigger than
    // we would ever need.
    MovieData* responses = (MovieData*) malloc(sizeof(MovieData)*maxMovies);

    //Print a welcome message
    cout << "Welcome to the Local Movie Database." << endl;

    //Keep executing the menu iteration function until it returns false.
    while (menuIteration(responses, &movieCount, maxMovies));

    //Print a goodbye message
    cout << "Goodbye." << endl;

    //Return status code 0 because nothing went wrong.
    return 0;
}
