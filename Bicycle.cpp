#include <iostream>
#include "Bicycle.h"

Bicycle::Person::~Person()
{
    std::cout << "Person destroyed " << std::endl;
}

Bicycle::Bicycle()
{
    std::cout << "'Bicycle' created" << std::endl;
}

void Bicycle::cycleAtSpeed(int s)
{
    speed = s;
    std::cout << "Speed " << speed << std::endl;
    std::cout << "cycle at speed" << std::endl;
}

bool Bicycle::turn(std::string direction)
{
    direction = "neutral";
    std::cout << "turn" << std::endl;
    return true;
}

bool Bicycle::useBreak()
{
    std::cout << "useBreak" << std::endl;
    return true;
}

void Bicycle::doesSomethingInteresting(int variableA)
{
    if (variableA >= 5)
        std::cout << "Value is too big" << std::endl;

    for(;;) 
    {
        if (variableA >= 5) 
            break;

        ++ variableA;
        std::cout << "`variableA` --> " << variableA << std::endl;
    }
}

void Bicycle::printGear()
{
    std::cout << "**** Gear : " << this->gear << std::endl;
}

Bicycle::~Bicycle()
{
    std::cout << "Bicycle destroyed " << std::endl;
}
