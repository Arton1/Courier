#pragma once
#include <string>
#include <vector>

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
	Package* throwAwayLastPackage(); // \/
	//returns a pointer to a package 
	//that gets removed from an array inside the object. 
	//Have to be careful using it, as the memory has to be freed later on.
private:
	static const std::string LOCATION[]; //names of locations
	static int numberOfWarehouses; //amount of already created warehouses
};
