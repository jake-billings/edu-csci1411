#include <iostream>
#include <vector>
#include "Bank.h"
#include "functions.h"

using namespace std;

int main() {
    string tempName;
    int tempNumber, size;
    float tempBalance;
    Bank tempBank;

    vector<Bank> acctVector;
    cout << "How many records do you want to add?\n";
    cin >> size;
    cin.ignore();
    for (int i = 0; i < size; i++) {
        cout << "Name for customer " << i + 1 << endl;
        getline(cin, tempName);
        cout << "Number for customer " << i + 1 << endl;
        cin >> tempNumber;
        cout << "Balance for customer " << i + 1 << endl;
        cin >> tempBalance;
        cin.ignore(); //removes '/n' in buffer for next getline
        cout << endl;
        tempBank.setName(tempName);
        tempBank.setNumber(tempNumber);
        tempBank.increaseBalance(tempBalance);
        acctVector.push_back(tempBank);
    }

    bubbleSort(acctVector);

    for (int i = 0; i < acctVector.size(); i++) {
        cout << acctVector[i] << endl;
    }

    return 0;
}