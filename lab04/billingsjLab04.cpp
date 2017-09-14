/* Class: CSCI 1411-004
   Description: Accepts user input to calculate pi to a given degree of accuracy
   Lab Partner: Matt
   Status: successfully compiled and run on csegrid
*/

#include <iostream> //Include cout and cin
#include <iomanip>  //Include setprecision

//Use the standard namespace so that we don't have to keep typing std::
using namespace std;

//Declare a globally scoped constant representing the precision we want to print our results into the console with.
// This will be the number of decimal places the double is represented with in the cout.
// Accourding to https://stackoverflow.com/questions/9999221/double-precision-decimal-places,
// you don't need more than 17 decimal places to fully represent the content of a double.
const int OUTPUT_PRECISION = 17;

//Declare main()
int main() {
    //Declare an unsigned long representing the user's desired input precision in the scope of main()
    unsigned long inputPrecision;
   
    //Declare a do-while user input loop that terminates when the user no longer wishes to calculate pi.
    // If a user enters a 0, this would be a nonsensical state anyway because we cannot approximate with
    // 0 iterations. Thus, we use this input to signal program termination.
    do {
        //Collect user input for how many iterations with which they wish to calculate pi.
        cout << "With how many iteations do you wish to calculate pi? (Enter 0 to exit)" << endl;
        cin >> inputPrecision;
        
        //It does not make sense to try and calculate with 0 iterations, so just skip the calculation
        // if a user enters 0 iteratiosn as their goal. The loop logic will then terminate the program.
        if (inputPrecision>0) {
            //Initialize the approximate value of pi/4 as a double. We start at iteration n=1 because we
            // know the user selected at least 1 iteration. The loop below engages only for selections
            // n>1
            double piOverFour = 1; 
            
            //Perform each step of the calculations n>2. n=0 is nonsensical, and n=1 has already been
            // performed. Thus, this loop starts at n=2 (which is i=1).
            for (unsigned long i=1; i<inputPrecision; i++) {
                //Add step n of the Taylor polinomial to approximate pi where n=i+1
                // Calculate this step using 2k+1 to acquire odd numbers. 
                // (-1)^n is calculated as (i%2>0?-1:1) in order to decrease program size and complexity
                // by removing dependancy on a math library. This ternary expression will result in the
                // same alternating series as (-1)^n. I should probably write a formal proof for it, but
                // it's true. (-1)^n==(i%2>0?-1:1)
                piOverFour += 1.0/(2.0*i+1.0)*(i%2>0?-1:1);
            }
            
            //Calculate pi by multiplying the Taylor approximation of pi/4 by 4.
            // This step is performed outside of the loop in order to increase the efficency of the algorithm.
            // The multiplication by four only needs to be performed once.
            double pi = piOverFour * 4;
            
            //Set the desired precision of cout to the constant precision establish in the global variable OUTPUT_PRECISION then log pi
            cout << "Pi: " << setprecision(OUTPUT_PRECISION) <<  pi << endl;
        }
    } while (inputPrecision);
    
    //Return 0 exit code because there is no error case for this program.
    return 0;
}
