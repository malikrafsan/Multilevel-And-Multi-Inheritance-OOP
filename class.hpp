#pragma once

class Vehicle {
    protected:
        int absis, ordinat, passanger=1, maxSeats;
        double fuelCapacity = 0, maxFuel;
        bool isEngineOn = false;
        double speed = 0, maxSpeed;
        std::string lossFuelFormula, vehicleType;

    public:
        Vehicle(int x, int y);
        ~Vehicle();

        void setSpeed ();
        void turnOnEngine();
        void move();
        void addPassanger();
        void printInformation();
        void refuel();

        virtual void printCommand();
        virtual double lossFuel(int moveX, int moveY) = 0;
        virtual void printStats() = 0;
};

class LandVehicle: public Vehicle {
    protected:
        int number_of_wheels;

    public:
        LandVehicle(int x, int y);
};

class Motorcycle: public LandVehicle {
    protected:
        bool hasHelmStorage = false;

    public:
        Motorcycle(int x, int y);
        void addExternalHelmStorage();
        double lossFuel(int moveX, int moveY);
        void printStats();
        void printCommand();
        void printInformation();
        void addPassanger();
};

class Car: public LandVehicle {
    protected:
        bool usingNOS=false;

    public:
        Car(int x, int y);
        double lossFuel(int moveX, int moveY);
        void printStats();
        void printCommand();
        void useNOS();
};

class FlyingVehicle: public Vehicle {
    protected:
        int altitude=0, maxAlti;
    
    public:
        FlyingVehicle(int x, int y);
        void printCommand();
        void setAltitude();
        void printInformation();
        void move();
        void printStats();
};

class Plane: public FlyingVehicle {
    protected:
        int number_of_engine;
        std::string PlaneType;
    
    public:
        Plane(int x, int y);
        double lossFuel(int moveX, int moveY);
        void printCommand();
        void addPassanger();
};

class Helicopter: public FlyingVehicle {
    protected:
        int number_of_blade;
    
    public:
        Helicopter(int x, int y);
        double lossFuel(int moveX, int moveY);
        void printCommand();
};

class FlyingCar: public Car, public FlyingVehicle {
    private:
        bool isFlying=false;
    
    public:
        FlyingCar(int x, int y);
        void flying();
        void landing();
        void printCommand();
        double lossFuel(int moveX, int moveY);
        void printStats();
        void setAltitude();
};

void wrongInput();