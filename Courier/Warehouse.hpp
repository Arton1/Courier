#pragma once
#include <string>
#include <vector>

class Car;
class Company;
class Package;

class Warehouse {
	int id;
	std::vector<Package*> packetsInside;
public:
	Warehouse();
	~Warehouse();
	std::string getName() const ;
	int getId() const;
	int getPackagesAmount() const ;
	Package& getPackage(int id);
private:
	static const std::string LOCATION[];
	static int numberOfWarehouses;
};
