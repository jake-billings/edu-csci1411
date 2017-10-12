/**
 * Name: Jake Billings
 * Date: 10/12/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */

#include "CarFunctions.h"

#include <iostream>
#include "Car.h"
#include "CarFunctions.h"

using namespace std;
Car newCar(istream &in) {
    Car car1;
    cout << "Make: ";
    in.ignore();
    getline(in, car1.make);
    cout << "\nModel: ";
    getline(in, car1.model);
    cout << "\nYear: ";
    in >> car1.year;
    cout << endl;
    return car1;
}
bool addCar(Car carToAdd, Car carArray[], int &currentSize, const int MAXSIZE) {
    currentSize++;
    if (currentSize < MAXSIZE)
    {
        carArray[currentSize - 1] = carToAdd;
        return true; //successful add
    }
    else
        return false;
}
void listCars(ostream &out, Car carArray[], int &currentSize) {
    for (int i = 0; i < currentSize; i++)
    {
        out << "Car " << i + 1 << endl;
        out << carArray[i].make << endl;
        out << carArray[i].model << endl;
        out << carArray[i].year << endl << endl;
    }
}


void searchCarMake(string make, Car carArray[], int currentSize) {
    bool found = false;
    for (int i = 0; i < currentSize; i++)
    {
        if (carArray[i].make == make)
        {
            found = true;
            cout << "Car at position " << i << endl;
            cout << carArray[i].make << endl;
            cout << carArray[i].model << endl;
            cout << carArray[i].year << endl<<endl;
        }//if
    }//for
    if (!found)
        cout << "Record not found\n";
}

void sortCarMake(Car carArray[], int currentSize) {
    //bubble sort
    int maxElement;
    int index;

    for (maxElement = currentSize - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (carArray[index].make > carArray[index + 1].make)
            {
                //swap the entire record (make, model and year)
                swap(carArray[index].make, carArray[index + 1].make);
                swap(carArray[index].model, carArray[index + 1].model);
                swap(carArray[index].year, carArray[index + 1].year);

            }//if
        }//for
    }//for
}//swap

void swap(int&a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}
