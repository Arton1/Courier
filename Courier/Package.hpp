#pragma once
#include <string>

class Warehouse;

class Package {
	int weight;
	int volume;
	int dest;
public:
	Package(Warehouse *vLocation);
	int getWeight() const;
	int getVolume() const;
	int getDestination() const;
	bool doesDestinationMatch(Warehouse *warehouse);
};