#include "Warehouse.hpp"

const std::string Warehouse::LOCATION[Warehouse::AMOUNTOFWAREHOUSES] = {
	"Warszawa",
	"Krakow",
	"Wroclaw",
	"Kazimierz Dolny",
	"Gdansk",
	"Szczecin",
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