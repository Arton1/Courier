#pragma once
#include <string>
#include <vector>

class Car;
class Company;

class Warehouse {
	int id;
	std::vector<Car*> carsInWarehouse;
public:
	Warehouse();
	std::string getName();

	static const int AMOUNTOFWAREHOUSES = 5;
private:
	static const std::string LOCATION[AMOUNTOFWAREHOUSES];
	static const int AMOUNTOFCARS = 10;
	static int numberOfWarehouses;
};
