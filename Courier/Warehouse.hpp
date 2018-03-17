#pragma once
#include <string>
#include <vector>

typedef Car;

class Warehouse {
	std::string location;
	std::vector<Car> cars;
public:
	Warehouse();
};