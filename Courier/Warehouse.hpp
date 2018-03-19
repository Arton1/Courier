#pragma once
#include <string>
#include <vector>
#include "Car.hpp"

class Warehouse {
	std::string location;
	std::vector<Car> cars;
public:
	Warehouse();
};