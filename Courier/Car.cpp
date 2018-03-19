#include "Car.hpp"
#include "Package.hpp"

Car::Car() {

}

void Car::buy() {

}

void Car::sell(){

}

void Car::go() {
	this->state = State::ROUTE;
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

}