/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#include "LeakedObjectDetector.h"

#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */




#include <iostream>

/*
 copied UDT 1:
 */

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

Bicycle::Person::~Person()
{
    std::cout << "Person destroyed " << std::endl;
}

Bicycle::Bicycle()
{
    std::cout << "'Bicycle' created" << std::endl;
}

void Bicycle::cycleAtSpeed(int s)
{
    speed = s;
    std::cout << "Speed " << speed << std::endl;
    std::cout << "cycle at speed" << std::endl;
}

bool Bicycle::turn(std::string direction)
{
    direction = "neutral";
    std::cout << "turn" << std::endl;
    return true;
}

bool Bicycle::useBreak()
{
    std::cout << "useBreak" << std::endl;
    return true;
}

void Bicycle::doesSomethingInteresting(int variableA)
{
    if (variableA >= 5)
        std::cout << "Value is too big" << std::endl;

    for(;;) 
    {
        if (variableA >= 5) 
            break;

        ++ variableA;
        std::cout << "`variableA` --> " << variableA << std::endl;
    }
}

void Bicycle::printGear()
{
    std::cout << "**** Gear : " << this->gear << std::endl;
}

Bicycle::~Bicycle()
{
    std::cout << "Bicycle destroyed " << std::endl;
}

struct BicycleWrapper 
{
    BicycleWrapper(Bicycle* ptr) : pointerToBicycle( ptr ) { }
    ~BicycleWrapper()
    {
        delete pointerToBicycle;
    }

    Bicycle* pointerToBicycle = nullptr;
};

/*
 copied UDT 2:
 */

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

Dishwasher::Dish::~Dish()
{
    std::cout << "Dish destroyed " << std::endl;
}

Dishwasher::Dishwasher(int power) : powerConsumption (power)
{
    std::cout << "'Dishwasher' created" << std::endl;
}

void Dishwasher::washDishes(int time)
{
    std::cout << "Input voltage is " << inputVoltage << std::endl;
    std::cout << "clean dishes for some time " << time << std::endl;
}

void Dishwasher::informUser()
{
    std::cout << "Eco rating is " << ecoRating << std::endl;
    std::cout << "job finished !" << std::endl;;
}

bool Dishwasher::lockDoor()
{
    return true;
}

void Dishwasher::doesSomethingInteresting()
{
    int inc = 0;
    std::cout << "'inc' initialized with value " << inc << std::endl;
    for (int i = 0; i < 5; ++i) 
    {        
        inc += 5;
        std::cout << "'inc' incremented by 5 --> " << inc << std::endl;
    }
    std::cout << "'inc' Final value " << inc << std::endl;
}

void Dishwasher::printinputVoltage()
{
    std::cout << "**** inputVoltage : " << this->inputVoltage << std::endl;
}

Dishwasher::~Dishwasher()
{
    std::cout << "Dishwasher destroyed " << std::endl;
}

struct DishwasherWrapper 
{
    DishwasherWrapper(Dishwasher* ptr) : pointerToDishwasher( ptr ) { }
    ~DishwasherWrapper()
    {
        delete pointerToDishwasher;
    }

    Dishwasher* pointerToDishwasher = nullptr;
};


/*
 copied UDT 3:
 */

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

Truck::Truck(int speed, int truckWeight) : speedLimit (speed), weight(truckWeight)
{
    std::cout << "'Truck' created" << std::endl;
}

void Truck::fitTrailer(std::string trailerType, int trailerLegnth)
{
    std::cout << "Type of engine " << typeOfEngine << std::endl;

    if (trailerType == "long" && trailerLegnth > 100)
        speedLimit = 50;

    std::cout << "fitTrailer" << std::endl;
    // do some other stuff ...
}

bool Truck::moveFood(int quantity)
{
    std::cout << "moveFood quantity " << quantity << std::endl;
    return true;
}

void Truck::drive(int speed, int distance)
{
    std::cout << "drive at " << speed << "for " << distance << std::endl;
}

int Truck::doesSomethingInteresting()
{
    bool flag = true;
    int x = 0;
    while(flag) 
    {        
        if (x >= 3) 
            flag = false;

        ++ x;
    }
    return x;
}

Truck::~Truck()
{
    std::cout << "Truck destroyed " << std::endl;
}

struct TruckWrapper 
{
    TruckWrapper(Truck* ptr) : pointerToTruck( ptr ) { }
    ~TruckWrapper()
    {
        delete pointerToTruck;
    }

    Truck* pointerToTruck = nullptr;
};


/*
 new UDT 4:
 with 2 member functions
 */

struct Kitchen
{
    Kitchen();
    ~Kitchen();

    Dishwasher dishwasher;

    void start(Dishwasher* dishwasher);
    void stop(Dishwasher* dishwasher);

    JUCE_LEAK_DETECTOR(Kitchen)
};

Kitchen::Kitchen(): dishwasher(100)
{
    std::cout << "Initialize the kitchen and it's Dishwasher " << std::endl;
}

Kitchen::~Kitchen()
{
    std::cout << "Destroy Kitchen " << std::endl;
}

void Kitchen::start(Dishwasher* dishwasherMachine)
{
    std::cout << "Start Dishwasher of capacity " << dishwasherMachine->capacity << std::endl;
}

void Kitchen::stop(Dishwasher* dishwasherMachine)
{
    std::cout << "Stop Dishwasher of capacity " << dishwasherMachine->capacity << std::endl;
}

struct KitchenWrapper 
{
    KitchenWrapper(Kitchen* ptr) : pointerToKitchen( ptr ) { }
    ~KitchenWrapper()
    {
        delete pointerToKitchen;
    }

    Kitchen* pointerToKitchen = nullptr;
};

/*
 new UDT 5:
 with 2 member functions
 */

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

Garage::Garage() : truck(200, 30)
{
    std::cout << "Initialize Garage" << std::endl;
}

Garage::~Garage()
{
    std::cout << "Destroy Garage" << std::endl;
}

void Garage::park(Bicycle* vehicle1, Truck* vehicle2)
{
    std::cout << "Park vehicle1 at speed" << vehicle1->speed << std::endl;
    std::cout << "Park vehicle2 of weight" << vehicle2->weight << std::endl;
}

void Garage::repair(Truck* vehcile)
{
    std::cout << "Repair axle " << vehcile->numberOfAxle << " of Truck " << std::endl;
}

struct GarageWrapper 
{
    GarageWrapper(Garage* ptr) : pointerToGarage( ptr ) { }
    ~GarageWrapper()
    {
        delete pointerToGarage;
    }

    Garage* pointerToGarage = nullptr;
};

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
