#include <iostream>
#include "class.hpp"

Vehicle::Vehicle(int x, int y) {
    absis = x;
    ordinat = y;
}

Vehicle::~Vehicle() { 
    std::cout<<"         ,--.!,  " <<std::endl;
    std::cout<<"      __/   -*-  " <<std::endl;
    std::cout<<"    ,d08b.  '|`  " <<std::endl;
    std::cout<<"    0088MM      "<<std::endl;
    std::cout<<"    `9MMP'      " <<std::endl;

    if (vehicleType == "Flying Car") {
        std::cout << "Actually we have to bomb your vehicle again because the car part is still survive >:(\n" << std::endl;
    } else {
        std::cout<< "Your " << vehicleType << " has been blown up :D" << std::endl;
    }
}

void Vehicle::setSpeed (){
    if (!isEngineOn) {
        std::cout << "The engine is not turned on yet" << std::endl;
        return;
    }

    double newSpeed;
    std::cout << "New speed: "; std::cin >> newSpeed;
    if (newSpeed < 0) {
        std::cout << "Speed cannot be under 0" << std::endl;
    } else if (newSpeed > maxSpeed) {
        std::cout << "Your speed cannot exceed speed limit: " << maxSpeed << std::endl;
    } else {
        speed = newSpeed;
        std::cout << "Speed has been changed to " << newSpeed << std::endl;
    }
}

void Vehicle::turnOnEngine(){
    if (isEngineOn){
        std::cout << "Engine is already on" << std::endl;
        return;
    }
    isEngineOn = true;
    std::cout<<"Engine is turned on" << std::endl;
}

void Vehicle::move() {
    if (!isEngineOn) {
        std::cout << "The engine is not turned on yet" << std::endl;
        return;
    }

    if (speed == 0) {
        std::cout << "Please set your speed > 0 first" << std::endl;
        return;
    }

    int x, y;
    std::cout << "Please input how much you wanna go" << std::endl;
    std::cout << "X direction: "; std::cin >> x;
    std::cout << "Y direction: "; std::cin >> y;

    int moveX = x, moveY = y;
    if (x < 0) { moveX = -x; }
    if (y < 0) { moveY = -y; }
    double loss = lossFuel(moveX,moveY); 
    
    if (loss > fuelCapacity){
        std::cout << "Not enough fuel" << std::endl;
        return;
    } else {
        absis += x;
        ordinat += y;
        fuelCapacity -= loss;
        std::cout << "You have moved to (" << absis << "," << ordinat << ")" << std::endl;
    }
}

void Vehicle::addPassanger() {
    if (passanger < maxSeats){
        passanger += 1;
        std::cout << "Passanger has been added" << std::endl;
    } else {
        std::cout << "Seats are full" << std::endl;
    }
}

void Vehicle::printCommand() {
    std::cout << "> " << vehicleType << " Commands" << std::endl;
    std::cout << "1. Turn on engine" << std::endl;
    std::cout << "2. Set speed" << std::endl;
    std::cout << "3. Move" << std::endl;
    std::cout << "4. Refuel" << std::endl;
    std::cout << "5. Add passanger" << std::endl;
    std::cout << "6. Display information" << std::endl;
    std::cout << "7. Display " << vehicleType << " statistics" << std::endl;
}

void Vehicle::printInformation() {
    std::cout << "\n> Information <" << std::endl;
    std::cout << "1. Engine is " << (isEngineOn ? "on" : "off") <<std::endl;
    std::cout << "2. Speed: " << speed <<std::endl;
    std::cout << "3. Position: (" << absis << "," << ordinat << ")" <<std::endl;
    std::cout << "4. Fuel: " << fuelCapacity <<std::endl;
    std::cout << "5. Passanger: " << passanger << std::endl;
}

void Vehicle::printStats() {
    std::cout << "> " << vehicleType << " Statistics <" << std::endl;
    std::cout << "1. LossFuel : " << lossFuelFormula << std::endl;
    std::cout << "2. Maximum number of seats : 2" << std::endl;
    std::cout << "3. Maximum fuel capacity : " << maxFuel << std::endl;
    std::cout << "4. Maximum speed: " << maxSpeed << std::endl;
}

void Vehicle::refuel() {
    fuelCapacity = maxFuel;
    std::cout << "Your " << vehicleType << " has been refueled" << std::endl;
}

// =========================================================================================

LandVehicle::LandVehicle(int x,int y): Vehicle(x,y) {}

// =========================================================================================

Motorcycle::Motorcycle(int x, int y): LandVehicle(x,y) {
    char YN;
    std::cout << "Do you want your motorcycle to have helm storage? (Y/N) "; std::cin >> YN;
    while (YN != 'Y' and YN != 'N'){
        wrongInput();
        std::cout << "Do you want your motorcycle to have helm storage? (Y/N) "; std::cin >> YN;
    }

    std::cout << "\n" << std::endl;
    std::cout<< "   ,_o     " << std::endl;
    std::cout<< ".-/c-/,::  " << std::endl;
    std::cout<< "(_)'==(_)  " << std::endl;

    hasHelmStorage = (YN == 'Y' ? true : false);
    std::cout<< "Your motorcycle in (" << absis << "," << ordinat << ") ";
    if (hasHelmStorage) {
        std::cout << "with helm storage";
    } else {
        std::cout << "without helm storage";
    }
    std::cout << " has been magically created :D" <<std::endl;

    number_of_wheels = 2;
    maxSeats = 2;
    maxSpeed = 10;
    maxFuel = 500;
    lossFuelFormula = "0.5 * (speed*moveX + speed*moveY) * passanger";
    vehicleType = "Motorcycle";
}

void Motorcycle::addExternalHelmStorage(){
    if (hasHelmStorage){
        std::cout << "Already has helm storage" << std::endl;
    } else {
        hasHelmStorage = true;
        std::cout << "External helm storage has been added" << std::endl;
    }
}

double Motorcycle::lossFuel(int moveX, int moveY) {
    return 0.5*(speed*moveX + speed*moveY)*passanger;
}

void Motorcycle::printCommand(){
    Vehicle::printCommand();
    std::cout << "8. Add external helm storage" << std::endl;
    std::cout << "0. Stop riding\n" << std::endl;
    std::cout << "Input yout choice: ";
}

void Motorcycle::printInformation() {
    Vehicle::printInformation();
    std::cout << "6. Has helm storage: " << (hasHelmStorage ? "yes" : "no") <<std::endl;
}

void Motorcycle::addPassanger() {
    if (hasHelmStorage) {
        Vehicle::addPassanger();
    } else {
        std::cout << "Please add helm storage before add passanger" << std::endl;
    }
}

// =========================================================================================

Car::Car(int x, int y): LandVehicle(x,y) {
    std::cout << "How many number of seats of your car: "; std::cin >> maxSeats;
    while (maxSeats < 1) {
        std::cout << "Your input is invalid, number of seats must be > 1" << std::endl;
        std::cout << "How many number of seats of your car: "; std::cin >> maxSeats;
    }

    std::cout << "\n" << std::endl;
    std::cout << "   ______         " << std::endl;
    std::cout << "  /|_||_\\`.__     " << std::endl;
    std::cout << " (   _    _ _\\    " << std::endl;
    std::cout << " =`-(_)--(_)-'    " << std::endl;

    std::cout<< "Your car in (" << absis << "," << ordinat << ") with " << maxSeats << " number of seats has been magically created :D" << std::endl;
    
    number_of_wheels = 4;
    maxSpeed = 20;
    maxFuel = 2000;
    lossFuelFormula = "speed * (1.5) * (moveX + moveY) * (0.75 * passanger)";
    vehicleType = "Car";
}

double Car::lossFuel(int moveX, int moveY) { 
    return (speed * (1.5) * (moveX + moveY) * (0.75 * passanger)); 
}

void Car::printCommand() {
    Vehicle::printCommand();
    std::cout << "8. Use NOS (increase max speed)" << std::endl;
    std::cout << "0. Stop driving\n" << std::endl;
    std::cout << "Input yout choice: ";
}

void Car::useNOS() {
    if (usingNOS) {
        std::cout << "You are already using NOS" << std::endl;
    } else {
        usingNOS = true;
        maxSpeed = 1.5 * maxSpeed;
    }
}

// =========================================================================================

FlyingVehicle::FlyingVehicle(int x, int y): Vehicle(x,y) {}

void FlyingVehicle::printCommand() {
    Vehicle::printCommand();
    std::cout << "8. Set your flying height" << std::endl;
}

void FlyingVehicle::printInformation() {
    Vehicle::printInformation();
    std::cout << "7. Altitude: " << altitude << std::endl;
}

void FlyingVehicle::move() {
    if (altitude <= 0) {
        std::cout << "Your altitude must be > 0 first to move" << std::endl;
    } else {
        Vehicle::move();
    }
}

void FlyingVehicle::printStats() {
    Vehicle::printStats();
    std::cout << "5. Maximum altitude: " << maxAlti << std::endl;
}

void FlyingVehicle::setAltitude() {
    int newAltitude;
    std::cout << "New altitude: "; std::cin >> newAltitude;

    if (newAltitude >= 0 && newAltitude <= maxAlti) {
        altitude = newAltitude;
        std::cout << "Your current altitude is " << newAltitude << std::endl;
    } else {
        std::cout << vehicleType << " altitude must be >= 0 and <= " << maxAlti << std::endl;
    }
}

// =========================================================================================

Plane::Plane(int x, int y): FlyingVehicle(x,y) {
    int choice;

    std::cout << "Please choose your plane" << std::endl;
    std::cout << "1. Boeing (number of seats: 7.000, max fuel capacity: 80.000)" << std::endl;
    std::cout << "2. Airbus (number of seats: 10.000, max fuel capacity: 100.000)" << std::endl;
    std::cout << "3. Customize (number of seats & max fuel capacity are customizable)" << std::endl;
    
    while (true) {
        std::cout << "Input your choice: "; std::cin >> choice;
        
        if (choice == 1) {
            PlaneType = "Boeing";
            maxSeats = 7000;
            maxFuel = 80000;
            break;
        } else if (choice == 2) {
            PlaneType = "Airbus";
            maxSeats = 10000;
            maxFuel = 100000;
            break;
        } else if (choice == 3) {
            std::cout << "Input your plane type: "; std::cin >> PlaneType;
            std::cout << "Input your plane number of seats: "; std::cin >> maxSeats;
            while (maxSeats < 1) {
                std::cout << "number of seats must be > 1" << std::endl;
                std::cout << "Input your plane max seats: "; std::cin >> maxSeats;
            }
            std::cout << "Input your plane maximum fuel capacity: "; std::cin >> maxFuel;
            while (maxFuel <= 0) {
                std::cout << "maximum fuel capacity must be > 0" << std::endl;
                std::cout << "Input your plane maximum fuel capacity: "; std::cin >> maxSeats;
            }
            break;
        } else {
            wrongInput();
        }
    }

    while (true) {
        std::cout << "Please input your number of engines: "; std::cin >> number_of_engine;
        if (number_of_engine <= 1) {
            std::cout << "Number of engine must be > 1\n" << std::endl;
            std::cout << "Please input your number of engines: "; std::cin >> number_of_engine;
        } else {
            break;
        }
    }

    std::cout << "\n" << std::endl;
    std::cout << "       __|__          " << std::endl;
    std::cout << "--------(_)--------   " << std::endl;
    std::cout << "  O  O       O  O     " << std::endl;

    std::cout << "\nYour " << PlaneType << " plane with " << number_of_engine << " number of engines and " << maxSeats << " number of seats has been magically created :D" << std::endl;

    maxAlti = 20000;
    maxSpeed = 100;
    lossFuelFormula = "2 * speed * (moveX + moveY) * (0.5 * passanger) * ((25.000 - altitude) / 10.000)";
    vehicleType = "Plane";
}

void Plane::printCommand() {
    FlyingVehicle::printCommand();
    std::cout << "0. Stop flying\n" << std::endl;
    std::cout << "Input yout choice: ";
}

double Plane::lossFuel(int moveX, int moveY) { 
    return 2 * speed * (moveX + moveY) * (1+ 0.1*passanger) * ((25000 - altitude) / 10000);
}

void Plane::addPassanger() {
    int added;
    std::cout << "Input how many added passanger: "; std::cin >> added;
    if (added < 0) {
        wrongInput();
        return;
    }
    if ((added + passanger) <= maxSeats) {
        passanger += added;
        std::cout << added << " passanger has been added" << std::endl;
    } else {
        std::cout << "Seats are full, with passanger: " << passanger << " and max seats: " << maxSeats << std::endl; 
    }
}

// =========================================================================================

Helicopter::Helicopter(int x, int y): FlyingVehicle(x,y) {
    while (true) {
        std::cout << "Please input your number of blades: "; std::cin >> number_of_blade;
        if (number_of_blade <= 0) {
            std::cout << "Number of engine must be > 0\n" << std::endl;
            std::cout << "Please input your number of blades: "; std::cin >> number_of_blade;
        } else {
            break;
        }
    }

    std::cout << "\n" << std::endl;
    std::cout << "   -----|-----    " << std::endl;
    std::cout << "*>=====[_]L)      " << std::endl;
    std::cout << "      -'-`-       " << std::endl;
    std::cout << "Your helicopter with " << number_of_blade << " number of blades has been magically created :D" << std::endl;

    maxSpeed = 40;
    maxFuel = 5000;
    maxAlti = 4000;
    lossFuelFormula = "2 * speed * (moveX + moveY) * (0.5 * passanger) * ((25.000 - altitude) / 10.000)";
    vehicleType = "Helicopter";
}

double Helicopter::lossFuel(int moveX, int moveY) { 
    return (speed * (1.75) * (moveX + moveY) * (1 + passanger) + (5000 - altitude)/1000); 
}

void Helicopter::printCommand() {
    FlyingVehicle::printCommand();
    std::cout << "0. Stop flying\n" << std::endl;
    std::cout << "Input yout choice: ";
}

// =========================================================================================

FlyingCar::FlyingCar(int x, int y): Car(x,y), FlyingVehicle(x,y) {
    number_of_wheels = 4;
    FlyingVehicle::maxSpeed = 50;
    FlyingVehicle::maxFuel = 2000;
    maxAlti = 5000;
    FlyingVehicle::vehicleType = "Flying Car";
    FlyingVehicle::lossFuelFormula = "(speed * (1.5) * (moveX + moveY) * (0.75 * passanger)) * (1 - (altitude/(2 * maxAltitude))";
}

void FlyingCar::flying(){
    if (isFlying) {
        std::cout << "You are already flying" << std::endl;
    } else {
        isFlying = true;
        std::cout << "Now you are flying" << std::endl;
    }
}

void FlyingCar::landing(){
    if (!isFlying) {
        std::cout << "You are already on the road" << std::endl;
    } else {
        isFlying = true;
        altitude = 0;
        std::cout << "Now you are on the road" << std::endl;
    }
}

void FlyingCar::printCommand() {
    FlyingVehicle::printCommand();
    std::cout << "9. Start flying" << std::endl;
    std::cout << "10. Use land road" << std::endl;
    std::cout << "11. Use NOS" << std::endl;
    std::cout << "0. Stop travelling\n" << std::endl;
    std::cout << "Input yout choice: ";
}

double FlyingCar::lossFuel(int moveX, int moveY) { 
    return (FlyingVehicle::speed * (1.5) * (moveX + moveY) * (0.75 * FlyingVehicle::passanger)) * (1 - (altitude/(2*maxAlti)));     
}

void FlyingCar::setAltitude(){
    if (isFlying) {
        FlyingVehicle::setAltitude();
    } else {
        std::cout << "You must start flying first" << std::endl;
    }
}

// =========================================================================================

void wrongInput(){
    std::cout << "Your input is invalid!" << std::endl;
}