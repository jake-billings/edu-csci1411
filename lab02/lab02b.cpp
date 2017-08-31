#include <iostream>

using namespace std;

int main() {
    int int1 = 5, int2 = 9, intResult;
    double double1 = 5.0, double2 = 9.0, doubleResult;
    const int SIZE = 10;
    
    intResult = int1 / int2;//int divided by int is an int!
    cout << int1 << "/" << int2 << "=" << intResult;
    doubleResult = double1 / double2;//double divided by a double is a double
    
    cout << double1 << "/" << double2 << "=" << doubleResult;
    cout << "Division with one double and one int is a double\n";
    cout << "5/9.0 =" << 5 / 9.0 << endl;
    cout << "5.0/9 =" << 5.0 / 9 << endl;
    
    cout << "Convert an int to a double" << double(int1);
    
    cout << "You can increment an int or double with ++:" << endl;
    int1++;
    cout << int1++ << endl;
    cout << "But you can not change the value of a const";
    
    //take a screen shot of the error below then remove the statement
    //SIZE++;
	
    return 0;
}
