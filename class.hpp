#pragma once

class Vehicle {
    protected:
        // Attributes
        int absis, ordinat, passanger=1, maxSeats;
        double fuelCapacity = 0, maxFuel;
        bool isEngineOn = false;
        double speed = 0, maxSpeed;
        std::string lossFuelFormula, vehicleType;

    public:
        //Constructor
        Vehicle(int x, int y);
        // I.S. x and y are defined
        // F.S. Vehicle object is constructed

        //Destructor
        ~Vehicle();
        // I.S. Vehicle object is defined 
        // F.S. Vehicle onject is destructed

        // Methods
        void setSpeed ();
        // I.S. speed is defined
        // F.S. value of speed is changed

        void turnOnEngine();
        // I.S. isEngineOn is defined
        // F.S. isEngineOn is assigned true

        void move();
        // I.S. absis and ordinat are defined
        // F.S. value of absis and ordinat are changed according to input user

        void addPassanger();
        // I.S. passanger and maxSeats are defined
        // F.S. passanger value is added by 1

        void printInformation();
        // I.S. isEngineOn, speed, absis, ordinat, fuelCapacity, and passanger are defined
        // F.S. Information about isEngineOn, speed, absis, ordinat, fuelCapacity, and passanger are displayed on the screen

        void refuel();
        // I.S. vehicleType and maxFuel are defined
        // F.S. fuelCapacity is assigned by maxFuel value

        void printStats();
        // I.S. vehicleType, lossFuelFormula, maxFuel, maxSpeed are defined
        // F.S. Statistics about the vehicle are displayed on the screen

        // Virtual methods
        virtual void printCommand() = 0;
        // I.S. vehicleType is defined
        // F.S. Command that vehicle can be performed are displayed on the screen

        virtual double lossFuel(int moveX, int moveY) = 0;
        // isn't implemented in Vehicle class
};

class LandVehicle: public Vehicle {
    protected:
        // Attribute
        int number_of_wheels;

    public:
        // Constructor
        LandVehicle(int x, int y);
        // I.S. Vehicle::Vehicle is defined
        // F.S. LandVehicle object is constructed
};

class Motorcycle: public LandVehicle {
    protected:
        // Attribute
        bool hasHelmStorage = false;

    public:
        // Constuctor
        Motorcycle(int x, int y);
        // I.S. LandVehicle::LandVehicle is defined
        // F.S. Motorcycle object is constructed and its attributes are defined

        // Methods
        void addExternalHelmStorage();
        // I.S. hasHelmStorage is defined
        // F.S. hasHelmStorage value is assigned by true

        void printCommand();
        // I.S. Vehicle::printCommand() is defined
        // F.S. Command that vehicle + motorcycle only can be performed are displayed on the screen

        void printInformation();
        // I.S. Vehicle::printInformation() is defined
        // F.S. Information about isEngineOn, speed, absis, ordinat, fuelCapacity, and passanger, also helm storage are displayed on the screen

        void addPassanger();
        // I.S. Vehicle::addPassanger() is defined
        // F.S. passanger value is added by 1

        double lossFuel(int moveX, int moveY);
        // Return lossFuel according to how far motorcycle go (moveX, moveY), speed, and passanger
};

class Car: public LandVehicle {
    protected:
        // Attribute
        bool usingNOS=false;

    public:
        // Constructor
        Car(int x, int y);
        // I.S. LandVehicle::LandVehicle is defined
        // F.S. Car object is constructed and its attributes are defined

        // Methods
        void printCommand();
        // I.S. Vehicle::printCommand() is defined
        // F.S. Command that vehicle + car only can be performed are displayed on the screen
        
        void useNOS();
        // I.S. usingNOS is defined
        // F.S. usingNOS value is assigned to true 

        double lossFuel(int moveX, int moveY);
        // Return lossFuel according to how far Car go (moveX, moveY), speed, and passanger
};

class FlyingVehicle: public Vehicle {
    protected:
        // Attribute
        int altitude=0, maxAlti;
    
    public:
        // Constuctor
        FlyingVehicle(int x, int y);
        // I.S. Vehicle::Vehicle is defined
        // F.S. FlyingVehicle object is constructed

        // Methods
        void printCommand();
        // I.S. Vehicle::printCommand() is defined
        // F.S. Command that vehicle + FlyingVehicle class only can be performed are displayed on the screen
        
        void setAltitude();
        // I.S. altitude and maxAlti are defined
        // F.S. altitude value is assigned according to user's input

        void printInformation();
        // I.S. Vehicle::printInformation() and altitude are defined
        // F.S. Information about isEngineOn, speed, absis, ordinat, fuelCapacity, and passanger, also altitude are displayed on the screen

        void move();
        // I.S. altitude and Vehicle::move() are defined
        // F.S. value of absis and ordinat are changed according to input user

        void printStats();
        // I.S. Vehicle::printStats() and maxAlti are defined 
        // F.S. Statistics about the FlyingVehicle are displayed on the screen
};

class Plane: public FlyingVehicle {
    protected:
        // Attribute
        int number_of_engine;
        std::string PlaneType;
    
    public:
        // Constructor
        Plane(int x, int y);
        // I.S. FlyingVehicle::FlyingVehicle is defined
        // F.S. Plane object is constructed and its attributes are defined

        // Methods
        void printCommand();
        // I.S. FlyingVehicle::printCommand() is defined
        // F.S. Command that vehicle + Plane only can be performed are displayed on the screen

        void addPassanger();
        // I.S. Vehicle::addPassanger() is defined
        // F.S. passanger value is added according to user's input

        double lossFuel(int moveX, int moveY);
        // Return lossFuel according to how far Plane go (moveX, moveY), speed, passanger, and altitude
};

class Helicopter: public FlyingVehicle {
    protected:
        // Attribute
        int number_of_blade;
    
    public:
        // Constructor
        Helicopter(int x, int y);
        // I.S. FlyingVehicle::FlyingVehicle is defined
        // F.S. Helicopter object is constructed and its attributes are defined

        void printCommand();
        // I.S. FlyingVehicle::printCommand() is defined
        // F.S. Command that vehicle + Helicopter only can be performed are displayed on the screen

        double lossFuel(int moveX, int moveY);
        // Return lossFuel according to how far Plane go (moveX, moveY), speed, passanger, and altitude
};

class FlyingCar: public Car, public FlyingVehicle {
    private:
        // Attribute
        bool isFlying=false;
    
    public:
        // Constuctor
        FlyingCar(int x, int y);
        // I.S. Car::Car() and FlyingVehicle::FlyingVehicle are defined
        // F.S. Flying car object is constructed and its attributes are defined

        void flying();
        // I.S. isFlying is defined
        // F.S. isFlying value is assigned to true

        void landing();
        // I.S. isFlying is defined
        // F.S. isFlying value is assigned to false and altitude value to 0

        void printCommand();
        // I.S. FlyingVehicle::printCommand() is defined
        // F.S. Command that vehicle + flying car only can be performed are displayed on the screen

        void setAltitude();
        // I.S. isFlying and FlyingVehicle::setAltitude() are defined
        // F.S. altitude value is assigned according to user's input

        double lossFuel(int moveX, int moveY);
        // Return lossFuel according to how far Plane go (moveX, moveY), speed, passanger, and altitude, also maxAlti
};

void wrongInput();
// I.S. Any state
// F.S. Invalid input message is displayed on the screen