#pragma once
#include <memory>
#include "Company.hpp"

class Simulator {
    std::unique_ptr<Company> company;
	int daysCounter;
	void simulate();
	void printInfo();
	void printCarsInfo();
	void printPackagesInfo();
	bool sellOption();
	bool moveOption();
	bool refillOption();
	bool loadOption();
	bool unloadOption();
public:
	Simulator();
	~Simulator() {};
	void menu();
};

