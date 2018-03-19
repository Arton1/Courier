#pragma once
#include <vector>
#include "Warehouse.hpp"

class Company {
	std::vector<Warehouse> warehouses;
	int money;
	
public:
	Company();
	~Company() {};
};