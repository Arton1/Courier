#pragma once
#include <list>
#include <vector>

class Warehouse;
class Car;

class Company {
	std::vector<Warehouse*> warehouses;
	std::vector<Car*> cars;
public:
	static const int AMOUNTOFWAREHOUSES = 5; //amount of warehouses in a company

	Company();
	~Company(); //frees the warehouse and car vectors.
	//getters
	Warehouse& getWarehouse(int id);
	Warehouse& operator[](int i);
	int getWarehousesAmount() const;
	int getCarsAmount() const;
	Car& getCar(int id);
	
	bool buyCar();
	//they call methods of the particular car instance
	bool sellCar(int id);
	bool loadCar(int id);
	bool unloadCar(int id);
};