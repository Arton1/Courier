#include "Company.hpp"
#include "Simulator.hpp"
#include <iostream>

using namespace std;

Simulator::Simulator() :
	daysCounter(0)
{
	company = make_unique<Company>();
}

void Simulator::menu() {
	cout << "Please, choose your option:" << endl;
	cout << "1 - Start a new simulation." << endl;
	cout << "2 - Quit" << endl;

	int option;
	while (1) {
		cin >> option;
		switch (option) {
		case 1:
			simulate();
			return;
		case 2:
			return;
		default:
			break;
		}
	}
}

void Simulator::simulate() {
	cout << endl;
	int option;
	while (1) {
		cout << "Please choose your option:" << endl;
		cout << "1 - Go into another day." << endl;
		cout << "2 - Quit" << endl;
		cin >> option;
		switch (option) {
		case 1:
			setNextDay();
			break;
		case 2:
			return;
		}
	}
}

void Simulator::setNextDay() { //losowanie sytuacji kolejnego dnia
	daysCounter++;
}