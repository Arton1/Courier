#pragma once

class Car {
	enum State {ROUTE, NOTHING, SERVICE};
	
	int mileage;
	int tankCapacity;
	int state;
	bool needRepairing;

	Car();
};