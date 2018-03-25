#include "Package.hpp"
#include "Warehouse.hpp"
#include "Company.hpp"
#include "Randomizer.hpp"

Package::Package(Warehouse *vLocation) :
	weight(5),
	volume(5)
{
	int randomNumber;
	do {
		randomNumber = Randomizer::getInstance().getRandomInt(Company::AMOUNTOFWAREHOUSES, 0);
	} while (vLocation->getId() == randomNumber);
	dest = randomNumber;
}

int Package::getWeight() const {
	return weight;
}

int Package::getDestination() const {
	return dest;
}

bool Package::doesDestinationMatch(Warehouse *warehouse) {
	if (warehouse->getId() == getDestination())
		return true;
	return false;
}

int Package::getVolume() const {
	return volume;
}