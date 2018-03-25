#include "Randomizer.hpp"

Randomizer::Randomizer() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	engine.seed(seed);
}

Randomizer& Randomizer::getInstance() {
	static Randomizer instance;
	return instance;
}

int Randomizer::getRandomInt(int range, int offset) {
	return engine() % range + offset;
}