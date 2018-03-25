#pragma once
#include <chrono>
#include <random>

class Randomizer { //singleton. It is used to get a random number.
private:
	std::mt19937 engine;
	Randomizer();
	Randomizer(const Randomizer &) {};
public:
	static Randomizer& getInstance();
	int getRandomInt(int range, int offset);
};