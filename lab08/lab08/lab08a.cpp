/**
 * Name: Jake Billings
 * Date: 10/12/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */

#include <iostream>
#include "Car.h"
#include "CarFunctions.h"

using namespace std;

int main() {
	const int MAXSIZE = 100;
	int currentSize = 0;
	Car car1;
	Car carArray[MAXSIZE];
	int menu;
	string make;
	bool done = false;
	while (!done) {
		cout << "1. Add a new car to the array\n";
		cout << "2. List out cars\n";
		cout << "3. Search for a car by Make\n";
		cout << "4. Sort cars by Make\n";
		cout << "5. exit\n";
		cin >> menu;
		switch (menu)
		{
		case 1: car1 = newCar(cin);
			addCar(car1, carArray, currentSize, MAXSIZE);
			break;
		case 2: listCars(cout, carArray, currentSize);
			break;
		case 3: cout << "What make do you want to search for? ";
			cin >> make;
			searchCarMake(make, carArray, currentSize);
			break;
		case 4:
			sortCarMake(carArray, currentSize);
			break;
		case 5: exit(0);
			break;
		default: cout << "Number between 1 and 5\n";
		}//switch
	}//while
}//main