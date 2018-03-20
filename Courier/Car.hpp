#pragma once
#include <vector>
#include "Package.hpp"

class Car {
	enum State {ROUTE, NOTHING, SERVICE};
	
	int mileage;
	int tankCapacity;
	State state;
	bool needRepairing;
	std::vector<Package> packages;

public:
	Car();
	~Car() {};
	void buy();
	void sell();
	void go();
	void unload();
	void load();
	void operator<<(Package package);
	void repair();
};