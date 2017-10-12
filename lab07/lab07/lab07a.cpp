#include <iostream>
#include "Car.h"
#include "CarFunctions.h"
using namespace std;
int main() {
	const int MAXSIZE = 2;
	int currentSize = 0;
	Car car1;
	Car carArray[MAXSIZE];
	int menu;
	bool done = false;
	while (!done)
	{
		cout << "1. Add a new car to the array\n";
		cout << "2. List out cars\n";
		cout << "3. exit\n";
		cin >> menu;
		switch (menu)
		{
		case 1: car1 = newCar(cin);
			addCar(car1, carArray, currentSize, MAXSIZE);
			break;
		case 2: listCars(cout, carArray, currentSize);
			break;
		case 3: exit(0);
			break;
		default: cout << "Number between 1 and 3\n";
		}//switch
	}//while
}//main
