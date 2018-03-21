#include "Car.hpp"
#include "Package.hpp"
#include "Company.hpp"
#include "Randomizer.h"

Car::Car(Warehouse &warehouse) :
	mileage(0),
	tankCapacity(100),
	needRepairing(false),
	state(State::NOTHING),
	timer(0)
{
	location = &warehouse;
}

void Car::go(Warehouse &warehouse) {
	if (state == State::ROUTE)
		return;
	location = &warehouse;
	timer = MAXTIME;
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

void Car::changeOverTime() {
	switch (state) {
	case State::ROUTE:
		tankCapacity -= getRandomInt(8, 5);
		if (getRandomInt(100, 0) < 7) {
			needRepairing = true;
			state = State::NOTHING;
		}
		++mileage;
		--timer;
		if (timer == 0)
			state = State::NOTHING;
		return;
	case State::SERVICE:
		--timer;
		return;
	default:
		break;
	}
	if (needRepairing) 
		if (getRandomInt(2, 0)) {
			state = State::SERVICE;
			timer = MAXTIME;
		}
	return;
}