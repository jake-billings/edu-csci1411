// Include cout and cin
#include <iostream>

// Using the standard namespace, so we don't have to use "std::"
using namespace std;

//Begin the main function
int main() {
    //Ask the customer what his or her name is
    cout << "Welcome to the Peanut Butter and Jelly store. Can I have your name?" << endl;
    
    //Read the name
    string name;
    cin >> name;
    
    //Make the peanut butter and jelly sandwich
    cout << "Spread peanut butter on bread" << endl;
    cout << "Spread jelly on bread" << endl;
    
    return 0;
}
