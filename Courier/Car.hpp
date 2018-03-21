#pragma once
#include <vector>
#include "Package.hpp"

class Company;
class Warehouse;

class Car {
	enum State {ROUTE, NOTHING, SERVICE};
	int mileage;
	int tankCapacity;
	State state;
	bool needRepairing;
	std::vector<Package> packages;
	Warehouse *location;
public:
	Car(Warehouse &warehouse);
	void go(Warehouse &warehouse);
	void unload();
	void load();
	void operator<<(Package package);
	void repair();

	//getters
	int getMileage() const;
	int getTankCapacity() const;
	int getState() const;
	std::string getStateString() const;
	bool getNeedRepairing() const;
	std::string getLocation() const;
};