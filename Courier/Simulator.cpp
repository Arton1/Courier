#include "Company.hpp"
#include "Simulator.hpp"
#include "Warehouse.hpp"
#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

int getRandomSeed() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 randomizer(seed);
	return randomizer() % 100000;
}


Simulator::Simulator() :
	daysCounter(0)
{
	company.buildWarehouse(5);
}

void Simulator::menu() {
	cout << "Please, choose your option:" << endl;
	cout << "1 - Start a new simulation." << endl;
	cout << "2 - Quit" << endl;
	char option;
	while (1) {
		cin >> option;
		switch (option) {
		case '1':
			simulate();
			return;
		case '2':
			return;
		default:
			break;
		}
	}
}

void Simulator::simulate() {
	cout << endl;
	char option;
	while (1) {
		printInfo();
		cout << "Please choose your option:" << endl;
		cout << "1 - Buy a car." << endl;
		cout << "2 - Sell a car." << endl;
		cout << "3 - Move a car to the other warehouse." << endl;
		cout << "4 - Unload a car." << endl;
		cout << "5 - Load a car." << endl;
		cout << "9 - Quit" << endl;
		cin >> option;
		cout << endl;
		switch (option) {
		case '1':
			company.buyCar();
			break;
		case '2':
			sellOption();
			break;
		case '9':
			return;
		default:
			break;
		}
	}
}

void Simulator::printInfo() {
	cout << "List of cars:" << endl;
	cout << "Id" << "      Location" << endl;
	printCarsInfo();
	cout << endl;
}

void Simulator::printCarsInfo() {
	for (int i = 0; i < company.getCarsAmount(); i++) {
		cout << i << " " << setw(5) << company.getCar(i).getMileage() << endl;
	}
	return;
}

void Simulator::sellOption() {
	cout << "Type number of a car you want to sell:" << endl;
	int option;
	cin >> option;
	if (company.sellCar(option))
		cout << "Car of number " << option << " succesfully sold." << endl;
	else
		cout << "Car of number " << option << " doesn't exist." << endl;
	cout << endl;
	return;
}