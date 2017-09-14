#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile("in.txt");
    ofstream outfile("out.txt");

    bool done = false;
    int menu=3, item;

    while (!done) {
        cout << "1. Read from and write to file\n";
        cout << "2. Exit\n";
        cin >> menu;
        switch (menu) {
        case 1: 
            while (infile >> item) {
                cout << item << endl;
                for (int i = 0; i < 5; i=i+2) {
                    item++;
                    cout << item << "\t";
                    outfile << item << "\t";
                }
                cout << endl;
                outfile << endl;
            }
            infile.close();
            outfile.close();
            cout << "done.\n";
                break;
        case 2:
            done = true;
            break;
        default:
            break;
        }
    }

    return 0;
}
