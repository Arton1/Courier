#pragma once
#include <memory>
#include "Company.hpp"

class Simulator {
    Company company;
	int daysCounter;
	void simulate();
	void setNextDay();
public:
	Simulator();
	~Simulator() {};
	void menu();
};

int getRandomSeed();