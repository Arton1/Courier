#pragma once
#include <list>
#include <vector>
#include "Warehouse.hpp"
#include "Car.hpp"

class Company {
	std::vector<Warehouse> warehouses;
	std::vector<Car> cars;
public:
	Company();
	void buildWarehouse(int howMany);
	Warehouse& getWarehouse(int id);
	Warehouse& operator[](int i);
	int getCarsAmount() const;
	Car& getCar(int id);
	bool buyCar();
	bool sellCar(int id);
};