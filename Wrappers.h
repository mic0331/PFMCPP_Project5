struct Dishwasher;
struct Bicycle;
struct Garage;
struct Kitchen;
struct Truck;

struct BicycleWrapper 
{
    BicycleWrapper(Bicycle* ptr) : pointerToBicycle( ptr ) { }
    ~BicycleWrapper()
    {
        delete pointerToBicycle;
    }

    Bicycle* pointerToBicycle = nullptr;
};


struct DishwasherWrapper 
{
    DishwasherWrapper(Dishwasher* ptr) : pointerToDishwasher( ptr ) { }
    ~DishwasherWrapper()
    {
        delete pointerToDishwasher;
    }

    Dishwasher* pointerToDishwasher = nullptr;
};

struct GarageWrapper 
{
    GarageWrapper(Garage* ptr) : pointerToGarage( ptr ) { }
    ~GarageWrapper()
    {
        delete pointerToGarage;
    }

    Garage* pointerToGarage = nullptr;
};

struct KitchenWrapper 
{
    KitchenWrapper(Kitchen* ptr) : pointerToKitchen( ptr ) { }
    ~KitchenWrapper()
    {
        delete pointerToKitchen;
    }

    Kitchen* pointerToKitchen = nullptr;
};

struct TruckWrapper 
{
    TruckWrapper(Truck* ptr) : pointerToTruck( ptr ) { }
    ~TruckWrapper()
    {
        delete pointerToTruck;
    }

    Truck* pointerToTruck = nullptr;
};

