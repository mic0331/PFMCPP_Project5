#include <iostream>
#include "Dishwasher.h"
#include "Kitchen.h"

Kitchen::Kitchen(): dishwasher(100)
{
    std::cout << "Initialize the kitchen and it's Dishwasher " << std::endl;
}

Kitchen::~Kitchen()
{
    std::cout << "Destroy Kitchen " << std::endl;
}

void Kitchen::start(Dishwasher* dishwasherMachine)
{
    std::cout << "Start Dishwasher of capacity " << dishwasherMachine->capacity << std::endl;
}

void Kitchen::stop(Dishwasher* dishwasherMachine)
{
    std::cout << "Stop Dishwasher of capacity " << dishwasherMachine->capacity << std::endl;
}
