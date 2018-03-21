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
		case '3':
			moveOption();
			break;
		case '9':
			return;
		default:
			break;
		}
	}
}

void Simulator::printInfo() {
	cout << "Locations: Warszawa, Krakow, Wroclaw, Szczecin, Gdansk" << endl;
	cout << "List of cars:" << endl;
	cout << left << setw(2) << "Id" << " "
		<< left << setw(7) << "Mileage" << " "
		<< left << setw(12) << "TankCapacity" << " "
		<< left << setw(10) << "State" << " "
		<< left << setw(13) << "NeedRepairing?" << " "
		<< left << setw(8) << "Location"
		<< endl;
	printCarsInfo();
	cout << endl;
}

void Simulator::printCarsInfo() {
	for (int i = 0; i < company.getCarsAmount(); i++) {
		Car &car = company.getCar(i);
		cout << left << setw(2) << i+1 << " "
			<< left << setw(7) << car.getMileage() << " "
			<< left << setw(12) << car.getTankCapacity() << " "
			<< left << setw(10) << car.getStateString() << " "
			<< left << setw(14) << car.getNeedRepairing() << " "
			<< left << setw(8) << car.getLocation()
			<< endl;
	}
	return;
}

void Simulator::sellOption() {
	cout << "Type number of a car you want to sell:" << endl;
	int option;
	cin >> option;
	if (company.sellCar(option - 1))
		cout << "Car of number " << option << " succesfully sold." << endl;
	else
		cout << "Car of number " << option << " doesn't exist." << endl;
	cout << endl;
	return;
}

bool Simulator::moveOption() {
	cout << "Which car do you want to move and where? (numbers only)" << endl;
	int id, location;
	cin >> id >> location;
	if (id < 1 || id > company.getCarsAmount()) {
		cout << "Car of this id doesn't exist." << endl;
		return false;
	}
	if (location < 1 || location > Warehouse::AMOUNTOFWAREHOUSES) {
		cout << "Location of this id doesn't exist." << endl;
		return false;
	}
	Car &car = company.getCar(--id);
	car.go(company[--location]);
	return true;
}