/**
 * Name: Jake Billings
 * Date: 10/12/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */


#ifndef CARFUNCTIONS_H
#define CARFUNCTIONS_H
#include "Car.h"
Car newCar(istream &in);
bool addCar(Car CarToAdd, Car carArray[], int &currentSize, const int MAXSIZE);
void listCars(ostream &out, Car carArray[], int &currentSize);
void searchCarMake(string make, Car carArray[], int currentSize);
void sortCarMake(Car carArray[], int currentSize);
void swap(int&a, int &b);
void swap(string &a, string &b);
#endif
