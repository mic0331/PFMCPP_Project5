#include <iostream>
#include "LeakedObjectDetector.h"

struct Dishwasher
{
    Dishwasher();
    Dishwasher(int );
    ~Dishwasher();

    double powerConsumption = 1200;
    double inputVoltage { 220 };
    int ecoRating = 7;
    int amountWaterUsed = 10;
    int capacity = 10;

    struct Dish
    {
        ~Dish();

        std::string dirtiness = "dirty";
        int length = 10;
        int height = 10;
        std::string material = "glass";
        std::string hardness = "soft";

        void breakDown();
        void supportHeat(int temperature);
        void cookFood(std::string foodType);
    };

    void washDishes(int time);
    void informUser();
    bool lockDoor();
    void doesSomethingInteresting();
    void printinputVoltage();

    JUCE_LEAK_DETECTOR(Dishwasher)
};
