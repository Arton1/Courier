#pragma once
#include <string>

class Package {
	int weight;
	int volume;
	std::string name;
	int id;
	std::string toWhere;
public:
	Package();
	~Package() {};
};