#pragma once
#include <memory>
#include "Company.hpp"

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