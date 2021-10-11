#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct Bicycle
{
    Bicycle();
    ~Bicycle();

    int gear = 21;
    std::string type = "road bike";
    int speed = 5;
    std::string cadance = "normal";
    std::string color = "Red";

    struct Person
    {
        ~Person();

        std::string firstName = "Bob";
        std::string lastName = "Sponge";
        int age = 14;

        bool useLeftFoot();
        bool useRightFoot();
        void listenMusic(std::string musicType);
    };

    void cycleAtSpeed(int speed);
    bool turn(std::string direction = "left");
    bool useBreak();
    void doesSomethingInteresting(int variableA);
    void printGear();

    JUCE_LEAK_DETECTOR(Bicycle)
};
