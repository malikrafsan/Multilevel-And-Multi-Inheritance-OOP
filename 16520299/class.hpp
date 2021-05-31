#pragma once

class Vehicle {
    protected:
        int number_of_wheels, absis, ordinat, number_of_seats, passanger, maxSeats, usedSeats;
        double fuelCapacity = 0;
        bool isEngineOn = false;
        double speed = 0;

    public:
        Vehicle(int x, int y);
        ~Vehicle();
        double getVelocity();
        void setSpeed (double newSpeed);
        void turnOnEngine();
        void move(int x, int y);
        void addPassanger();
        void printCommand();
        void printInformation();
        virtual double lossFuel(int inputX, int inputY, double inputSpeed) = 0;
        virtual void refuel() = 0;
        virtual void printStats() = 0;
};

class Motorcycle : public Vehicle {
    private:
        bool hasHelmStorage = false;

    public:
        Motorcycle(int x, int y, bool helmStorage);
        void addExternalHelmStorage();
        double lossFuel(int inputX, int inputY, double inputSpeed);
        void refuel();
        void printStats();
        void printCommand();
        void printInformation();
        void addPassanger();
};

class Car: public Vehicle {
    public:
        Car(int x, int y);
        double lossFuel(int inputX, int inputY, double inputSpeed);
        void refuel();
        void printStats();
        void printCommand();
        void printInformation();
};

void wrongInput();