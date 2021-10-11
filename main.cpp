/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


#include <iostream>
#include "Wrappers.h"
#include "Dishwasher.h"
#include "Bicycle.h"
#include "Truck.h"
#include "Kitchen.h"
#include "Garage.h"

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    // 1.
    DishwasherWrapper dishwasherWrapper (new Dishwasher (1500));
    dishwasherWrapper.pointerToDishwasher->washDishes(250);

    dishwasherWrapper.pointerToDishwasher->lockDoor();
    dishwasherWrapper.pointerToDishwasher->informUser();
    dishwasherWrapper.pointerToDishwasher->doesSomethingInteresting();
    std::cout << "**** inputVoltage : " << dishwasherWrapper.pointerToDishwasher->inputVoltage << std::endl;
    dishwasherWrapper.pointerToDishwasher->printinputVoltage();

    // 2.
    BicycleWrapper bicycleWrapper (new Bicycle());
    bicycleWrapper.pointerToBicycle->cycleAtSpeed(120);
    bicycleWrapper.pointerToBicycle->useBreak();
    bicycleWrapper.pointerToBicycle->turn("right");
    bicycleWrapper.pointerToBicycle->doesSomethingInteresting(125);
    bicycleWrapper.pointerToBicycle->doesSomethingInteresting(2);
    std::cout << "**** Gear : " << bicycleWrapper.pointerToBicycle->gear << std::endl;
    bicycleWrapper.pointerToBicycle->printGear();

    // 3.
    TruckWrapper truckWrapper (new Truck(120, 4565));
    truckWrapper.pointerToTruck->moveFood(300);
    truckWrapper.pointerToTruck->drive(140, 20);
    truckWrapper.pointerToTruck->fitTrailer("long", 120);
    std::cout << "Final value of X for Truck --> " << truckWrapper.pointerToTruck->doesSomethingInteresting() << std::endl;
    // 4.
    KitchenWrapper kitchenWrapper (new Kitchen());
    kitchenWrapper.pointerToKitchen->start(dishwasherWrapper.pointerToDishwasher);
    kitchenWrapper.pointerToKitchen->stop(dishwasherWrapper.pointerToDishwasher);
    // 5.
    Garage* garage = new Garage();
    GarageWrapper garageWrapper (garage);
    garage->park(bicycleWrapper.pointerToBicycle, truckWrapper.pointerToTruck);
    garage->repair(truckWrapper.pointerToTruck);    

    std::cout << "good to go!" << std::endl;
}
