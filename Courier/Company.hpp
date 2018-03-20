#pragma once
#include <vector>
#include "Warehouse.hpp"
#include "Car.hpp"

class Company {
	Company *instace;
	std::vector<Warehouse> warehouses;
	std::vector<Car> cars;
	int money;
public:
	Company();
	void buildWarehouse(int howMany);
	Warehouse& getWarehouse(int id);
	Warehouse& operator[](int i);
	friend static Car& Car::buy();

};