/**
 * Name: Jake Billings
 * Date: 11/16/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#include "Bank.h"

Bank::Bank() {
    name = "";
    number = 0;
    balance = 0;
}

Bank::Bank(string _name, int _number, float _balance) {
    name = _name;
    number = _number;
    balance = _balance;
}

void Bank::increaseBalance(float amount) {
    balance = balance + amount;
}
