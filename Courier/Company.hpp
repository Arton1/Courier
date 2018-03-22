#pragma once
#include <list>
#include <vector>
#include "Warehouse.hpp"
#include "Car.hpp"

class Company {
	std::vector<Warehouse*> warehouses;
	std::vector<Car*> cars;
public:
	static const int AMOUNTOFWAREHOUSES = 5;

	Company();
	~Company();
	Warehouse& getWarehouse(int id);
	Warehouse& operator[](int i);
	int getWarehousesAmount() const;
	int getCarsAmount() const;
	Car& getCar(int id);
	bool buyCar();
	bool sellCar(int id);
	bool loadCar(int id);
};