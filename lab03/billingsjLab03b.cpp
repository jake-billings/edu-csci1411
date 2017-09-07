#include <iostream>
#include <string>
using namespace std;

int main() {
    int x = 5, y = 10;
    if (x == 20)
    cout << "Used = instead of ==, making an aways true assignment statement\n";
    cout << "because no { } the if conditional only covers one line.  This line is always printed\n";

    switch (x) {
    case 5: cout << "five\n"; break;
    case 10: cout << "This line also prints because there is no break statement"; break;
    }
}

