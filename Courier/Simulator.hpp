#pragma once
#include <memory>

class Company;

class Simulator {
	std::unique_ptr<Company> company;
	int daysCounter;
	void simulate();
	void setNextDay();
public:
	Simulator();
	~Simulator() {};
	void menu();
};