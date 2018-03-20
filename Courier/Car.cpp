#include "Car.hpp"
#include "Package.hpp"
#include "Company.hpp"

Car::Car() :
	mileage(0),
	tankCapacity(100),
	needRepairing(false),
	state(State::NOTHING)
{
}

void Car::go(int idOfWarehouse) {
	state = State::ROUTE;
}

void Car::unload() {
	this->state = State::NOTHING;
}

void Car::load() {
	packages.push_back(Package());
}

void Car::operator<<(Package package) {
	packages.push_back(Package(package));
}

void Car::repair() {
	needRepairing = false;
	return;
}

Car& Car::buy() {
	
}