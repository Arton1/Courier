#include "Company.hpp"

Company::Company() :
	money(0)
{
}

void Company::buildWarehouse(int howMany) {
	for(int i = 0; i < howMany; i++)
		warehouses.push_back(Warehouse());
	return;
}

Warehouse& Company::getWarehouse(int id) {
	return warehouses[id];
}

Warehouse& Company::operator[](int id) {
	return warehouses[id];
}