#include "Car.hpp"
#include "Package.hpp"
#include "Company.hpp"

Car::Car(Warehouse &warehouse) :
	mileage(0),
	tankCapacity(100),
	needRepairing(false),
	state(State::NOTHING)
{
	location = &warehouse;
}

void Car::go(Warehouse &warehouse) {
	if (state == State::ROUTE)
		return;
	location = &warehouse;
	state = State::ROUTE;
	return;
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

int Car::getMileage() const {
	return mileage;
}
int Car::getTankCapacity() const {
	return tankCapacity;
}
int Car::getState() const {
	return state;
}
bool Car::getNeedRepairing() const {
	return needRepairing;
}

std::string Car::getStateString() const {
	switch (state) {
	case State::NOTHING:
		return "Nothing";
	case State::ROUTE:
		return "On route";
	case State::SERVICE:
		return "In service";
	default:
		return "BUG";
	}
}

std::string Car::getLocation() const {
	return location->getName();
}