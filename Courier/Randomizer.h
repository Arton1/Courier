#pragma once
#include <chrono>
#include <random>
#include <iostream>
using namespace std;

int getRandomInt(int range, int offset) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 randomizer(seed);
	return randomizer() % range + offset;
}