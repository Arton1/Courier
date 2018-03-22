#include "Warehouse.hpp"
#include "Package.hpp"
#include "Company.hpp"
#include <iostream>

int Warehouse::numberOfWarehouses = 0;

const std::string Warehouse::LOCATION[] = {
	"Warszawa",
	"Krakow",
	"Wroclaw",
	"Szczecin",
	"Gdansk"
};

Warehouse::Warehouse():
	id(numberOfWarehouses++)
{
	for (int i = 0; i < 5; i++) {
		packetsInside.push_back(new Package(this));
	}
}

Warehouse::~Warehouse() {
	for (int i = 0; i < packetsInside.size(); i++)
		delete packetsInside[i];
}

std::string Warehouse::getName() const {
	return Warehouse::LOCATION[id];
}

int Warehouse::getId() const {
	return id;
}

int Warehouse::getPackagesAmount() const {
	return packetsInside.size();
}

Package& Warehouse::getPackage(int id) {
	return *packetsInside[id];
}