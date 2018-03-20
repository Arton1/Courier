#pragma once
#include <vector>
#include "Package.hpp"

class Company;

class Car {
	enum State {ROUTE, NOTHING, SERVICE};
	
	int mileage;
	int tankCapacity;
	State state;
	bool needRepairing;
	std::vector<Package> packages;

public:
	Car();
	static Car& Car::buy();
	void go(int idOfWarehouse);
	void unload();
	void load();
	void operator<<(Package package);
	void repair();
};