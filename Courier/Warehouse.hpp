#pragma once
#include <string>
#include <vector>

class Car;

class Warehouse {
	std::string location;
	std::vector<Car> cars;
public:
	Warehouse();
};