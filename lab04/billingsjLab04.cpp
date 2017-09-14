/* Class: CSCI 1411-004
   Description: Accepts user input to calculate pi to a given degree of accuracy
   Lab Partner: Matt
    Status: successfully compiled and run on csegrid
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    unsigned long inputPrecision;
    
    //Accourding to https://stackoverflow.com/questions/9999221/double-precision-decimal-places, you don't need more than 17 decimal places.

    
    do {
        cout << "With how many iteations do you wish to calculate pi? (Enter 0 to exit)" << endl;
        cin >> inputPrecision;
        if (inputPrecision>0) {
            double piOverFour = 1; 
            for (unsigned long i=1; i<inputPrecision; i++) {
                piOverFour += 1.0/(2.0*i+1.0)*(i%2>0?-1:1);
            }
            cout << "Pi: " << setprecision(17) <<  piOverFour*4 << endl;
        }
        
    } while (inputPrecision);
    
    return 0;
}
