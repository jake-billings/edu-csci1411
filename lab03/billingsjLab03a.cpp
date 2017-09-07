#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    char go, menu = 'z';

    cout << "What is your full name (e.g. Tom Smith)?\n";
    getline(cin, name);
    cout << "\nWould you like to continue (y or n) ?\n";
    cin >> go;
    
    if (go == 'y' || go == 'Y') {    
        cout << "A. Print A\n";
        cout << "B. Print B\n";
        cin >> menu;

        switch (menu) {
        case 'a':
        case 'A':
            cout << "A";
            break;
        case 'b':
        case 'B':
            cout << "B";
            break;
        default:
            cout << "not A or B";
        }
    } else { 
        cout << "Goodbye";
    }
    
    return 0;
}
