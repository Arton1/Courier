#pragma once
#include <memory>
#include "Company.hpp"

class Simulator {
    Company company;
	int daysCounter;
	void simulate();
	void printInfo();
	void printCarsInfo();
	void sellOption();
	bool moveOption();
public:
	Simulator();
	~Simulator() {};
	void menu();
};

int getRandomSeed();