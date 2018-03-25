#pragma once
#include <memory>
#include "Company.hpp"

class Simulator { 
	
	//It is used to show that the other 
	//autonomous classes are working as they should.
	//Also grants a text interface, used to communicate with an user.
    
	std::unique_ptr<Company> company;
	void simulate();
	//printing functions
	void printInfo();
	void printCarsInfo();
	void printPackagesInfo();
	//options
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

