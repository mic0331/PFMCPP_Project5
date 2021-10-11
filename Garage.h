#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"
#include "Truck.h"
#include "Bicycle.h"

struct Garage
{
    Garage();
    ~Garage();

    Bicycle bicyle;
    Truck truck;

    void park(Bicycle*, Truck*);
    void repair(Truck*);

    JUCE_LEAK_DETECTOR(Garage)
};
