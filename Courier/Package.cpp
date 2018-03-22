#include "Package.hpp"
#include "Warehouse.hpp"
#include "Company.hpp"
#include "Randomizer.h"

Package::Package(Warehouse *vLocation) :
	weight(5),
	volume(5)
{
	int randomNumber;
	do {
		randomNumber = getRandomInt(Company::AMOUNTOFWAREHOUSES, 0);
	} while (vLocation->getId() == randomNumber);
}

int Package::getWeight() const {
	return weight;
}

int Package::getDestination() const {
	return dest;
}