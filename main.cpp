/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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

Bicycle::~Bicycle()
{
    std::cout << "Bicycle destroyed " << std::endl;
}

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

Dishwasher::~Dishwasher()
{
    std::cout << "Dishwasher destroyed " << std::endl;
}


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


/*
 new UDT 4:
 with 2 member functions
 */

struct Kitchen
{
    Kitchen();
    ~Kitchen();

    Dishwasher dishwasher;

    void start(Dishwasher dishwasher);
    void stop(Dishwasher dishwasher);
};

Kitchen::Kitchen(): dishwasher(100)
{
    std::cout << "Initialize the kitchen and it's Dishwasher " << std::endl;
}

Kitchen::~Kitchen()
{
    std::cout << "Destroy Kitchen " << std::endl;
}

void Kitchen::start(Dishwasher dishwasherMachine)
{
    std::cout << "Start Dishwasher of capacity " << dishwasherMachine.capacity << std::endl;
}

void Kitchen::stop(Dishwasher dishwasherMachine)
{
    std::cout << "Stop Dishwasher of capacity " << dishwasherMachine.capacity << std::endl;
}

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

    void park(Bicycle, Truck);
    void repair(Truck);
};

Garage::Garage() : truck(200, 30)
{
    std::cout << "Initialize Garage" << std::endl;
}

Garage::~Garage()
{
    std::cout << "Destroy Garage" << std::endl;
}

void Garage::park(Bicycle vehicle1, Truck vehicle2)
{
    std::cout << "Park vehicle1 at speed" << vehicle1.speed << std::endl;
    std::cout << "Park vehicle2 of weight" << vehicle2.weight << std::endl;
}

void Garage::repair(Truck vehcile)
{
    std::cout << "Repair axle " << vehcile.numberOfAxle << " of Truck " << std::endl;
}

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
    Dishwasher dishwasher (1500);
    dishwasher.washDishes(250);
    dishwasher.lockDoor();
    dishwasher.informUser();
    dishwasher.doesSomethingInteresting();
    // 2.
    Bicycle bicycle;
    bicycle.cycleAtSpeed(120);
    bicycle.useBreak();
    bicycle.turn("right");
    bicycle.doesSomethingInteresting(125);
    bicycle.doesSomethingInteresting(2);
    // 3.
    Truck truck (120, 4565);
    truck.moveFood(300);
    truck.drive(140, 20);
    truck.fitTrailer("long", 120);
    std::cout << "Final value of X for Truck --> " << truck.doesSomethingInteresting() << std::endl;
    // 4.
    Kitchen kitchen;
    kitchen.start(dishwasher);
    kitchen.stop(dishwasher);
    // 5.
    Garage garage;
    garage.park(bicycle, truck);
    garage.repair(truck);    

    std::cout << "good to go!" << std::endl;
}
