#include <iostream>
#include "Truck.h"

Truck::Truck(int speed, int truckWeight) : speedLimit (speed), weight(truckWeight)
{
    std::cout << "'Truck' created" << std::endl;
}

void Truck::fitTrailer(std::string trailerType, int trailerLegnth)
{
    std::cout << "Type of engine " << typeOfEngine << std::endl;

    if (trailerType == "long" && trailerLegnth > 100)
        speedLimit = 50;

    std::cout << "fitTrailer" << std::endl;
    // do some other stuff ...
}

bool Truck::moveFood(int quantity)
{
    std::cout << "moveFood quantity " << quantity << std::endl;
    return true;
}

void Truck::drive(int speed, int distance)
{
    std::cout << "drive at " << speed << "for " << distance << std::endl;
}

int Truck::doesSomethingInteresting()
{
    bool flag = true;
    int x = 0;
    while(flag) 
    {        
        if (x >= 3) 
            flag = false;

        ++ x;
    }
    return x;
}

Truck::~Truck()
{
    std::cout << "Truck destroyed " << std::endl;
}
