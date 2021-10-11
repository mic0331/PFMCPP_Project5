#include <iostream>
#include "Truck.h"
#include "Bicycle.h"
#include "Garage.h"

Garage::Garage() : truck(200, 30)
{
    std::cout << "Initialize Garage" << std::endl;
}

Garage::~Garage()
{
    std::cout << "Destroy Garage" << std::endl;
}

void Garage::park(Bicycle* vehicle1, Truck* vehicle2)
{
    std::cout << "Park vehicle1 at speed" << vehicle1->speed << std::endl;
    std::cout << "Park vehicle2 of weight" << vehicle2->weight << std::endl;
}

void Garage::repair(Truck* vehicle)
{
    std::cout << "Repair axle " << vehicle->numberOfAxle << " of Truck " << std::endl;
}
