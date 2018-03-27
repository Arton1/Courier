#include "Courier/Simulator.hpp"
#include <memory>"

int main()
{
	std::unique_ptr<Simulator> simulator(new Simulator());
	simulator->menu();
    return 0;
}
