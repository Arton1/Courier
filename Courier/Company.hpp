#pragma once
#include <vector>

class Warehouse;

class Company {
	std::vector<Warehouse> warehouses;
	int money;
	
public:
	Company();
	~Company() {};
};