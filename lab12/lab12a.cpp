/**
 * Name: Jake Billings
 * Date: 11/16/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#include <iostream>
#include "Bank.h"
using namespace std;
int main() {
    const int SIZE = 2;
    string tempName;
    int tempNumber;
    float tempBalance;

    Bank acctArray[SIZE];
    for (int i=0; i<SIZE; i++) {
        cout << "Name for customer " << i+1 <<endl;
        getline(cin,tempName);
        cout << "Number for customer " << i+1 <<endl;
        cin >> tempNumber;
        cout <<"Balance for customer " << i+1 <<endl;
        cin >> tempBalance;
        cin.ignore(); //removes '/n' in buffer for next getline
        cout <<endl;
        acctArray[i].setName(tempName);
        acctArray[i].setNumber(tempNumber);
        acctArray[i].increaseBalance(tempBalance);

    }

    for (int i=0; i<SIZE; i++) {
        cout << acctArray[i].getName() << endl;
        cout << acctArray[i].getNumber()<<endl;
        cout << acctArray[i].getBalance()<<endl<<endl;
    }
    return 0;
}
