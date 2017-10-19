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

int main() {
    int *arrayPtr;

    int size = 4, inc = 3;
    arrayPtr = allocateArray(size);
    for (int i = 0; i < size; i++)
        arrayPtr[i] = i;
    listArray(arrayPtr, size);
    arrayPtr = increaseArray(arrayPtr,size, inc);
    listArray(arrayPtr, size);

	system("pause");

    return 0;
}
