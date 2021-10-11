#include <iostream>
#include "Wrappers.h"

BicycleWrapper::BicycleWrapper(Bicycle* ptr) : pointerToBicycle( ptr ) { }

BicycleWrapper::~BicycleWrapper()
{
    delete pointerToBicycle;
}

DishwasherWrapper::DishwasherWrapper(Dishwasher* ptr) : pointerToDishwasher( ptr ) { }

DishwasherWrapper::~DishwasherWrapper()
{
    delete pointerToDishwasher;
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