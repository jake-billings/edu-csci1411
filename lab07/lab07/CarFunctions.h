#ifndef CARFUNCTIONS_H
#define CARFUNCTIONS_H
#include "Car.h"

Car newCar(istream &in);
bool addCar(Car CarToAdd, Car carArray[], int &currentSize, const int MAXSIZE);
void listCars(ostream &out, Car carArray[], int &currentSize);

#endif
