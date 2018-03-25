#include "Company.hpp"
#include "Warehouse.hpp"
#include "Car.hpp"

Company::Company()
{
	for (int i = 0; i < AMOUNTOFWAREHOUSES; i++)
		warehouses.push_back(new Warehouse());
}

Company::~Company() {
	for (int i = 0; i < AMOUNTOFWAREHOUSES; i++)
		delete warehouses[i];
	for (int i = 0; i < cars.size(); i++)
		delete cars[i];
}

Warehouse& Company::getWarehouse(int id) {
	return *warehouses[id];
}

Warehouse& Company::operator[](int id) {
	return *warehouses[id];
}

int Company::getCarsAmount() const {
	return cars.size();
}

Car& Company::getCar(int id) {
	if (!(id < 0 || id >= cars.size()))
		return *cars[id];
}

bool Company::buyCar() {
	cars.push_back(new Car(warehouses[0]));
	return true;
}

bool Company::sellCar(int id) {
	if (id < 0 || id >= cars.size())
		return false;
	delete cars[id];
	std::vector<Car*>::iterator iterator;
	iterator = cars.begin();
	advance(iterator, id);
	cars.erase(iterator);
	return true;
}

bool Company::loadCar(int id) {
	if (id < 0 || id >= cars.size())
		return false;
	cars[id]->load();
	return true;
}

bool Company::unloadCar(int id) {
	if (id < 0 || id >= cars.size())
		return false;
	cars[id]->unload();
	return true;
}


int Company::getWarehousesAmount() const {
	return warehouses.size();
}