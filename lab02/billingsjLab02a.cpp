#include <iostream>  //cin and cout
#include <string>    //string
using namespace std; //namespace for cin and cout

int main() {	
    double celsius, fahren;
    int count;
    string firstName, lastName;
    cout << "What is your first name?" << endl;
    cin >> firstName;
    cout << "What is your last name?" << endl;
    cin >> lastName;
    cout << "What is the fahrenheit temperature?\n";
    cin >> fahren;
    
    celsius = (fahren - 32) * (5.0 / 9.0);
    
    cout << firstName << " " <<lastName << ", the Celsius temperature is " << celsius << endl;
    
    return 0; //that is a zero not an Oh
}

