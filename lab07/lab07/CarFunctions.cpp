#include <iostream>
#include "Car.h"
#include "CarFunctions.h"

using namespace std;
Car newCar(istream &in)
{
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
bool addCar(Car carToAdd, Car carArray[], int &currentSize, const int MAXSIZE)
{

	if (currentSize < MAXSIZE)
	{
		carArray[currentSize] = carToAdd;
		currentSize++;
		return true; //successful add
	}
	else
		return false;
}
void listCars(ostream &out, Car carArray[], int &currentSize)
{
	for (int i = 0; i < currentSize; i++)
	{
		out << "Car " << i + 1 << endl;
		out << carArray[i].make << endl;
		out << carArray[i].model << endl;
		out << carArray[i].year << endl << endl;
	}
}
