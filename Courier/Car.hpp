#pragma once
#include <vector>

class Package;

class Car {
	enum State {ROUTE, NOTHING, SERVICE};
	
	int mileage;
	int tankCapacity;
	int state;
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