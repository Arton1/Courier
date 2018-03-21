#include "Company.hpp"

Company::Company()
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

int Company::getCarsAmount() const {
	return cars.size();
}

Car& Company::getCar(int id) {
	return cars[id];
}

void Company::buyCar() {
	cars.push_back(Car());
}

bool Company::sellCar(int id) {
	if (id >= cars.size())
		return false;
	std::vector<Car>::iterator iterator;
	iterator = cars.begin();
	advance(iterator, id);
	cars.erase(iterator);
	return true;
}