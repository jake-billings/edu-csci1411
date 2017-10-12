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

//Include string tools
#include <string>

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
string toLowerCase(string a);
void readMoviesFromFile(MovieData* movies, unsigned int* movieCount, unsigned int maxMovies);
void addMovie(MovieData* movies, unsigned int* movieCount, unsigned int maxMovies);
void printMovie(MovieData movie, unsigned int index);
void printMovies(MovieData* movies, unsigned int* movieCount);
void sortAllMoviesAlphabeticallyByTitle(MovieData* movies, unsigned int* movieCount);
void searchMoviesByTitle(MovieData* movies, unsigned int* movieCount);


//------Function Implementations------
/**
 * Returns a new string that is the lowercase equivalent of the parameter string a
 *
 * @param a a std::string to convert to lowercase
 * @return a new string that is the lowercase equivalent of the parameter string a
 */
string toLowerCase(string a) {
    string aLower(a);

    //For each position in a, copy the value and lowercase the value if it's an uppercase letter
    // takes advantage of properties of ASCII and C++ character storage
    for (int i=0; i<a.length(); i++) {
        if((a[i]<='Z') && (a[i]>='A')) {
            aLower[i] =  (((char) a[i])-('A'-'a'));
        }
    }

    return aLower;
}

/**
 * Reads MovieDatas from file into memory
 *
 * @param movies The array of MovieDatas to read into
 * @param movieCount The number of MovieDatas already in that array
 * @param maxMovies The maximum number of MovieDatas that can fit in the array
 */
void readMoviesFromFile(MovieData* movies, unsigned int* movieCount, unsigned int maxMovies) {
    //Find out what file to read from
    string filePath;
    cout << "What file would you like to read from? (The default movies are in \"data.bin\".)" << endl;
    //cin.ignore(); //Ignore since we're using getline()
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
void addMovie(MovieData* movies, unsigned int* movieCount, unsigned int maxMovies) {
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
 * Sorts all movies in the movies array alphabetically by alphabetizing the array by title in memory
 *
 * @param movies The array of movies to read into
 * @param movieCount The number of movies already in that array
 */
void sortAllMoviesAlphabeticallyByTitle(MovieData* movies, unsigned int* movieCount) {
    //Sort the movies in memory using bubble sort by type
    //Perform a double iteration over the array
    for (unsigned long i = 0; i < *movieCount; i++) {
        for (unsigned long j = 0; j+1 < *movieCount; j++) {
            //Cache the movie at index j
            MovieData r = movies[j];

            //Compare the alphabetical index of movies[j] and movies[j+1] using the > operator
            if (r.title > movies[j+1].title) {

                //Swap the movies if they are in the wrong order
                movies[j] = movies[j+1];
                movies[j+1] = r;
            }
        }
    }
}

/**
 * Searches all movies in the movies array for one that contains a substring
 *
 * @param movies The array of movies to read into
 * @param movieCount The number of movies already in that array
 */
void searchMoviesByTitle(MovieData* movies, unsigned int* movieCount) {
    //Ask the user for a substring to search for within each movie title
    string searchRaw;
    cout << "What would you like to search for?" << endl;
    cin.ignore(); //ignore the previous endl
    getline(cin, searchRaw);

    //Convert the user's search to to lowercase so that we can do case-insensitive searches
    string lowercaseSearch = toLowerCase(searchRaw);

    //Allocate a counter to track how many results we found a printed.
    unsigned int resultCount = 0;

    //For each movie, print it out if it contains the search term
    for (unsigned long i = 0; i < *movieCount; i++) {
        // Use the function tolower() to convert both strings to lowercase before the search
        // as a result, the case of the search term will be irrelevant to the search results.
        string lowerCaseMovieTitle = toLowerCase(movies[i].title);

        //Check if the movie title contains the search term by running find() and checking
        // if the return value is greater than string::npos. String::npos is a constant
        // defined in the standard library defined as -1. find() returns string::npos if the
        // term search is not found in the string.
        if (lowerCaseMovieTitle.find(lowercaseSearch) != string::npos) {
            //If this movie matches the search term, print it.
            printMovie(movies[i], i);

            //If this movie matches the search term, increment the result count.
            resultCount++;
        }
    }

    //Print a message acknowledging how many movies we found
    if (resultCount) {
        cout << "Showing all " << resultCount << " results with titles containing \"" << lowercaseSearch << "\"." << endl;
    } else {
        cout << "Sorry. No results were found with titles containing \"" << lowercaseSearch << "\"." << endl;
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
bool menuIteration(MovieData* movies, unsigned int* movieCount, unsigned int maxMovies) {
    //Print the menu options.
    cout << "Please select one of the following using the letter." << endl;
    cout << "1.\tRead movies from a file" << endl;
    cout << "2.\tAdd Movie" << endl;
    cout << "3.\tList Movies" << endl;
    cout << "4.\tSearch Movie by Title" << endl;
    cout << "5.\tSort Movies by Title" << endl;
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
            searchMoviesByTitle(movies, movieCount);
            break;
        case 5:
            sortAllMoviesAlphabeticallyByTitle(movies, movieCount);
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
    //Set a cap on the number of movies we can store that is way bigger than we would ever need
    unsigned int maxMovies = 1024;

    //Keep track of how many movies are in our array
    unsigned int movieCount = 0;

    //Allocate an array in memory to store our potential movies that is far bigger than
    // we would ever need.
    MovieData* movies = (MovieData*) malloc(sizeof(MovieData)*maxMovies);

    //Print a welcome message
    cout << "Welcome to the Local Movie Database." << endl;

    //Keep executing the menu iteration function until it returns false.
    while (menuIteration(movies, &movieCount, maxMovies));

    //Print a goodbye message
    cout << "Goodbye." << endl;

    //Return status code 0 because nothing went wrong.
    return 0;
}
