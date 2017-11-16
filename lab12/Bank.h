/**
 * Name: Jake Billings
 * Date: 11/16/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;

class Bank {
private:
    string name;
    int number;
    float balance;
public:
    Bank(); //default constructor
    Bank(string _name, int _number, float _balance); //constructor

    string getName(){return name;}
    void setName(string _name){name=_name;}
    int getNumber() {return number;}
    void setNumber(int _number){number = _number;}
    float getBalance(){return balance;}
    void increaseBalance(float amount);
};
#endif
