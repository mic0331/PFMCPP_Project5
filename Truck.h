#include <iostream>
#include "LeakedObjectDetector.h"

struct Truck
{
    Truck(int speedLimit, int weight);
    Truck();
    ~Truck();

    int numberOfAxle = 4;
    std::string typeOfEngine = "diesel";
    std::string color = "Pink";
    int speedLimit = 90;
    double weight = 1530.00;
    unsigned int y;

    void fitTrailer(std::string trailerType, int trailerLegnth);
    bool moveFood(int quantity);
    void drive(int speed, int distance);
    int doesSomethingInteresting();

    JUCE_LEAK_DETECTOR(Truck)
};
