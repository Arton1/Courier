#include "Company.hpp"
#include "Simulator.hpp"
#include "Warehouse.hpp"
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

Simulator::Simulator() :
	daysCounter(0)
{
	company = make_unique<Company>();
	company->buildWarehouse(5);
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
		cout << endl;
		cout << "Please choose your option:" << endl;
		cout << "1 - Go into another day." << endl;
		cout << "2 - Quit" << endl;
		cin >> option;
		switch (option) {
		case '1':
			setNextDay();
			break;
		case '2':
			return;
		case '3':
			
			break;
		default:
			break;
		}
	}
}

void Simulator::setNextDay() { //losowanie sytuacji kolejnego dnia
	daysCounter++;
	for(int i=0; i<Warehouse::AMOUNTOFWAREHOUSES; i++)
//		company[i]
}

int getRandomSeed() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 randomizer(seed);
	return randomizer() % 100000;
}