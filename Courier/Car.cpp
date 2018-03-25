#include "Car.hpp"
#include "Package.hpp"
#include "Company.hpp"
#include "Randomizer.hpp"

Car::Car(Warehouse *warehouse) :
	mileage(0),
	tankCapacity(100),
	needRepairing(false),
	state(State::NOTHING),
	timer(0)
{
	location = warehouse;
}

Car::~Car() {
	for (int i = 0; i < packages.size(); i++)
		delete packages[i];
}

void Car::changeOverTime() {
	switch (state) {
	case State::ROUTE:
		tankCapacity -= Randomizer::getInstance().getRandomInt(8, 5);
		if (Randomizer::getInstance().getRandomInt(100, 0) < 7) {
			needRepairing = true;
			setState(State::NOTHING);
		}
		++mileage;
		--timer;
		if (timer == 0)
			setState(State::NOTHING);
		if (tankCapacity <= 0)
			setState(State::STUCK);
		return;
	case State::SERVICE:
		--timer;
		if (timer == 0) {
			setState(State::NOTHING);
			needRepairing = 0;
		}
		return;
	case State::NOTHING:
		if (needRepairing)
			if (Randomizer::getInstance().getRandomInt(2, 0)) {
				setState(State::SERVICE);
				setTimer();
			}
		return;
	case State::STUCK:
		return;
	}
}

void Car::go(Warehouse *warehouse) {
	if (state == State::ROUTE || state == State::STUCK || location == warehouse)
		return;
	location = warehouse;
	setTimer();
	state = State::ROUTE;
	return;
}

void Car::unload() {
	for (int i = 0; i < packages.size(); i++) {
		if (packages.at(i)->getDestination() == location->getId()) {
			delete packages[i];
			std::vector<Package*>::iterator iterator;
			iterator = packages.begin();
			advance(iterator, i);
			packages.erase(iterator);
		}
	}
}

void Car::load(Package *package) {
	packages.push_back(package);
}

void Car::operator<<(Package *package) {
	packages.push_back(package);
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
	case State::STUCK:
		return "Stuck";
	default:
		return "BUG";
	}
}

std::string Car::getLocation() const {
	return location->getName();
}

void Car::refill() {
	if(timer == 0 && State::NOTHING)
		tankCapacity = 100;
	return;
}

void Car::setTimer() {
	timer = MAXTIME;
	return;
}

void Car::setState(State v_state) {
	state = v_state;
	return;
}