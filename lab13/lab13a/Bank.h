#ifndef BANK_H
#define BANK_H

#include <string>
#include <iostream>
using namespace std;
class Bank
{
private:
    string name;
    int number;
    float balance;
public:
    Bank();
    Bank(string _name, int _number, float _balance);
    string getName(){return name;}
    void setName(string _name){name=_name;}
    int getNumber() {return number;}
    void setNumber(int _number){number = _number;}
    float getBalance(){return balance;}
    void increaseBalance(float amount);

};
#endif
