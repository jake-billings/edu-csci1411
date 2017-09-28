/* Copied from Lab Document
 * 
 */
#include <iostream>
#include "Convert.h"

using namespace std;

int main() {
    double fahren, celsius;
    int value1 = 25;
    cout << "Temperature in Fahrenheit:";
    cin >> fahren;
    celsius = fahrenToCel(fahren);
    cout << fahren << " degrees fahrenheit equates to " << celsius << " degrees Celsius\n";
    cout << "Before running passByValue value1 = " << value1 << endl;
    passByValue(value1);
    cout << "After running passByValue value1 = " << value1 << endl;
    cout << "Before running passByReference value1 = " << value1 << endl;
    passByReference(value1);
    cout << "After running passByReference value1 = " << value1 << endl;
    return 0;
}
