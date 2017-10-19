/**
 * Name: Jake Billings
 * Date: 10/19/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */

#include <iostream>
#include "functions.h"

using namespace std;

int *allocateArray(int arraySize) {
    int *arrayPtr;
    arrayPtr = new int[arraySize];
    return arrayPtr;
}

int *increaseArray(int *arrayPtr, int &currentSize, int increaseBy) {
    int *newPtr;
    //create new array of larger size
    newPtr = new int[currentSize + increaseBy];

    //copy contents from old to new
    for (int i = 0; i < currentSize; i++) {
        newPtr[i] = arrayPtr[i];
    }
    //intialize additional cells to -1
    for (int i = currentSize; i < (currentSize + increaseBy); i++) {
        newPtr[i] = -1;
    }
    currentSize = currentSize + increaseBy;
    delete[] arrayPtr;
    return newPtr;
}

void listArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
