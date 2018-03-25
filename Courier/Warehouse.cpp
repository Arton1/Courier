#include "Warehouse.hpp"
#include "Package.hpp"
#include "Company.hpp"
#include "Randomizer.hpp"

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

bool Warehouse::addRandomAmountOfPackages() {
	int amount = Randomizer::getInstance().getRandomInt(5, 0);
	for(int i=0; i<amount; i++)
		packetsInside.emplace_back();
	return true;
}

Package* Warehouse::throwAwayLastPackage() { //please see the .hpp file before using.
	if (getPackagesAmount() == 0)
		return NULL;
	const int position = getPackagesAmount() - 1;
	std::vector<Package*>::iterator iterator;
	iterator = packetsInside.begin();
	advance(iterator, position);
	Package *package = packetsInside[position];
	packetsInside.erase(iterator);
	return package;
}