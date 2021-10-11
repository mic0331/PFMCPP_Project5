struct Dishwasher;
struct Bicycle;
struct Truck;
struct Garage;
struct Kitchen;

struct BicycleWrapper 
{
    Bicycle* pointerToBicycle = nullptr;

    BicycleWrapper(Bicycle* ptr);
    ~BicycleWrapper();
};

struct TruckWrapper 
{
    TruckWrapper(Truck* ptr);
    ~TruckWrapper();

    Truck* pointerToTruck = nullptr;
};

struct DishwasherWrapper 
{
    Dishwasher* pointerToDishwasher = nullptr;

    DishwasherWrapper(Dishwasher* ptr);
    ~DishwasherWrapper();
};

struct GarageWrapper 
{
    Garage* pointerToGarage = nullptr;
    
    GarageWrapper(Garage* ptr);
    ~GarageWrapper();    
};

struct KitchenWrapper 
{
    Kitchen* pointerToKitchen = nullptr;
    
    KitchenWrapper(Kitchen* ptr);
    ~KitchenWrapper();
};



