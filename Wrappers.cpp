#include <iostream>
#include "Wrappers.h"
#include "Bicycle.h"
#include "Dishwasher.h"
#include "Garage.h"
#include "Kitchen.h"
#include "Truck.h"

BicycleWrapper::BicycleWrapper(Bicycle* ptr) : pointerToBicycle( ptr ) { }

BicycleWrapper::~BicycleWrapper()
{
    delete pointerToBicycle;
}

DishwasherWrapper::DishwasherWrapper(Dishwasher* ptr) : pointerToDishwasher( ptr ) { }

 
DishwasherWrapper::~DishwasherWrapper()
{
    delete pointerToDishwasher; // because we're calling Dishwasher::~Dishwasher() when we delete the pointer.
}

GarageWrapper::GarageWrapper(Garage* ptr) : pointerToGarage( ptr ) { }

GarageWrapper::~GarageWrapper()
{
    delete pointerToGarage;
}

KitchenWrapper::KitchenWrapper(Kitchen* ptr) : pointerToKitchen( ptr ) { }

KitchenWrapper::~KitchenWrapper()
{
    delete pointerToKitchen;
}

TruckWrapper::TruckWrapper(Truck* ptr) : pointerToTruck( ptr ) { }

TruckWrapper::~TruckWrapper()
{
    delete pointerToTruck;
}
