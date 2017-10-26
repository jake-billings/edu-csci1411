/**
 * Name: Jake Billings
 * Date: 10/26/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#include <iostream>
#include "functions.h"
using namespace std;

char* backwardCString(char *cstring, int size) {

    char* backCString = new char[size];
    //remember that the backCString[size-1] needs to contain a '\n'.
    //'\n' is just one character
    backCString[size - 1] = '\n';

    //now we want to reverse all of the letters before the '\n'
    for (int i = 0; i < size; i++) {
        backCString[size-2 - i] = cstring[i];
    }
    return backCString;


}

string backwardString(string stringObject) {
    string backString = stringObject;
    for (int i=0; i < stringObject.size(); i++)
        backString[stringObject.size()-1 -i] = stringObject[i];
    return backString;
}

void printCString(char* cString, int size)
{
    for (int i = 0; i < size; i++)
        cout << cString[i];
    cout << endl;
}