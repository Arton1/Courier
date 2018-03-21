#include "Warehouse.hpp"

int Warehouse::numberOfWarehouses = 0;

const std::string Warehouse::LOCATION[Warehouse::AMOUNTOFWAREHOUSES] = {
	"Warszawa",
	"Krakow",
	"Wroclaw",
	"Szczecin",
	"Gdansk"
};

Warehouse::Warehouse():
	id(numberOfWarehouses++)
{
}

std::string Warehouse::getName() {
	return Warehouse::LOCATION[id];
}

void moveCars() {

}