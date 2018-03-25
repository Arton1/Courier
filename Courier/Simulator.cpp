#include "Company.hpp"
#include "Simulator.hpp"
#include "Warehouse.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Simulator::Simulator() :
	daysCounter(0)
{
	company = std::make_unique<Company>();
}

void Simulator::menu() {
	char option;
	while (1) {
		cout << "Please, choose your option:" << endl;
		cout << "1 - Start a new simulation." << endl;
		cout << "2 - Quit" << endl;
		cin >> option;
		switch (option) {
		case '1':
			simulate();
			break;
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
	bool success = false;
	while (1) {
		printInfo();
		cout << "Please choose your option:" << endl;
		cout << "1 - Buy a car." << endl;
		cout << "2 - Sell a car." << endl;
		cout << "3 - Move a car to the other warehouse." << endl;
		cout << "4 - Refill car" << endl;
		cout << "5 - Load a car." << endl;
		cout << "6 - Unload a car." << endl;
		cout << "9 - Quit" << endl;
		cout << "0 - Wait a day." << endl;
		cin >> option;
		cout << endl;
		switch (option) {
		case '1':
			success = company->buyCar();
			break;
		case '2':
			success = sellOption();
			break;
		case '3':
			success = moveOption();
			break;
		case '4':
			success = refillOption();
			break;
		case '5':
			success = loadOption();
			break;
		case '6':
			success = unloadOption();
			break;
		case '9':
			return;
		case '0':
			success = true;
			break;
		default:
			break;
		}
		if (success)
			for (int i = 0; i < company->getCarsAmount(); i++)
				company->getCar(i).changeOverTime();
		success = false;
	}
	return;
}

void Simulator::printInfo() {
	if (company->getCarsAmount() != 0) {
		cout << "Locations:" << endl << "Warszawa, Krakow, Wroclaw, Szczecin, Gdansk" << endl;
		printPackagesInfo();
		cout << left << ": Packages" << endl << endl;
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
}

void Simulator::printCarsInfo() {
	for (int i = 0; i < company->getCarsAmount(); i++) {
		Car &car = company->getCar(i);
		cout << left << setw(2) << i+1 << " "
			<< left << setw(7) << car.getMileage() << " "
			<< left << setw(12) << car.getTankCapacity() << " "
			<< left << setw(10) << car.getStateString() << " "
			<< left << setw(14) << car.getNeedRepairing() << " "
			<< left << setw(5) << car.getLocation()
			<< endl;
	}
	return;
}

void Simulator::printPackagesInfo() {
	for (int i = 0; i < company->getWarehousesAmount(); i++) 
			cout << left << setw((*company)[i].getName().length()+1) << (*company)[i].getPackagesAmount() << " ";
	return;
}

bool Simulator::sellOption() {
	cout << "Type number of a car you want to sell:" << endl;
	int option;
	cin >> option;
	if (company->sellCar(option - 1)) {
		cout << "Car of number " << option << " succesfully sold." << endl;
		cout << endl;
		return true;
	}
	else {
		cout << "Car of number " << option << " doesn't exist." << endl;
		cout << endl;
		return false;
	}
}

bool Simulator::moveOption() {
	cout << "Which car do you want to move and where? (numbers only)" << endl;
	int id, location;
	cin >> id >> location;
	if (id < 1 || id > company->getCarsAmount()) {
		cout << "Car of this id doesn't exist." << endl << endl;
		return false;
	}
	if (location < 1 || location > Company::AMOUNTOFWAREHOUSES) {
		cout << "Location of this id doesn't exist." << endl << endl;
		return false;
	}
	Car &car = company->getCar(--id);
	car.go(&(company->getWarehouse(--location)));
	return true;
}

bool Simulator::refillOption() {
	cout << "Which car do you want to refill?" << endl;
	int id;
	cin >> id;
	if (id < 1 || id > company->getCarsAmount()) {
		cout << "Car of this id doesn't exist." << endl << endl;
		return false;
	}
	Car &car = company->getCar(--id);
	car.refill();
	return true;
}

bool Simulator::loadOption() {
	cout << "Type number of a car you want to load:" << endl;
	int option;
	cin >> option;
	if (company->loadCar(option - 1)) {
		cout << "Car of number " << option << " succesfully sold." << endl;
		cout << endl;
		return true;
	}
	else {
		cout << "Car of number " << option << " doesn't exist." << endl;
		cout << endl;
		return false;
	}
}

bool Simulator::unloadOption() {
	return false;
}