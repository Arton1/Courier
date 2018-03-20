#include "Car.hpp"
#include "Package.hpp"

Car::Car():
	mileage(0),
	tankCapacity(100),
	needRepairing(false),
	state(State::NOTHING)
{

}

void Car::buy() {

}

void Car::sell(){

}

void Car::go() {
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