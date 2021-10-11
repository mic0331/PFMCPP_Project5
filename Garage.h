#include <iostream>
#include "LeakedObjectDetector.h"

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
