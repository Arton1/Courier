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
	int getDestination() const;
};