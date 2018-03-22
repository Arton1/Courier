#include "Simulator.hpp"
#include <memory>
int main()
{
	std::unique_ptr<Simulator> simulator;
	simulator = std::make_unique<Simulator>();
	simulator->menu();
    return 0;
}