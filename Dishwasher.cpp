#include <iostream>
#include "Dishwasher.h"

Dishwasher::Dish::~Dish()
{
    std::cout << "Dish destroyed " << std::endl;
}

Dishwasher::Dishwasher(int power) : powerConsumption (power)
{
    std::cout << "'Dishwasher' created" << std::endl;
}

void Dishwasher::washDishes(int time)
{
    std::cout << "Input voltage is " << inputVoltage << std::endl;
    std::cout << "clean dishes for some time " << time << std::endl;
}

void Dishwasher::informUser()
{
    std::cout << "Eco rating is " << ecoRating << std::endl;
    std::cout << "job finished !" << std::endl;;
}

bool Dishwasher::lockDoor()
{
    return true;
}

void Dishwasher::doesSomethingInteresting()
{
    int inc = 0;
    std::cout << "'inc' initialized with value " << inc << std::endl;
    for (int i = 0; i < 5; ++i) 
    {        
        inc += 5;
        std::cout << "'inc' incremented by 5 --> " << inc << std::endl;
    }
    std::cout << "'inc' Final value " << inc << std::endl;
}

void Dishwasher::printinputVoltage()
{
    std::cout << "**** inputVoltage : " << this->inputVoltage << std::endl;
}

Dishwasher::~Dishwasher()
{
    std::cout << "Dishwasher destroyed " << std::endl;
}
