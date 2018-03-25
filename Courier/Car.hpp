#pragma once
#include <vector>

class Company;
class Warehouse;
class Package;

class Car {
	enum State {ROUTE, NOTHING, SERVICE, STUCK};
	static const int MAXTIME = 4;	//number of ticks for "timer" variable.

	int mileage;
	int tankCapacity;
	State state;
	bool needRepairing;				//true if the car needs reparing, cant do anything if true and have to wait till repaired
	std::vector<Package*> packages;	//
	Warehouse *location;			//current location of car or location to which the car is going
	int timer;						//helping variable. Acts like a clock. It takes MAXTIME ticks to move a car or repair it.
private:
	void setTimer();				//sets "timer" variable to MAXTIME or decreases it by 1.
	void setState(State state);
public:
	Car(Warehouse *warehouse);
	~Car();							//frees the pointers of Package vector
	void go(Warehouse *warehouse);
	void unload();
	void load();
	void operator<<(Package *package); //used to push the particular package into a packages array
	void repair();
	void refill();
	void changeOverTime();			//makes use of "time" variable

	//getters
	int getMileage() const;
	int getTankCapacity() const;
	int getState() const;
	std::string getStateString() const;
	bool getNeedRepairing() const;
	std::string getLocation() const;
	int getPackagesAmount() const;
	int getPackagesMatchingAmount() const;
};