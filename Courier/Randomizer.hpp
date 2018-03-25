#pragma once
#include <chrono>
#include <random>

class Randomizer {
private:
	std::mt19937 engine;
	Randomizer();
	Randomizer(const Randomizer &) {};
public:
	static Randomizer& getInstance();
	int getRandomInt(int range, int offset);
};