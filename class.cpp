#include <iostream>
#include "class.hpp"

Vehicle::Vehicle(int x, int y) {
    // Defining absis and ordinat attribute
    absis = x;
    ordinat = y;
}

Vehicle::~Vehicle() {
    std::cout<<"         ,--.!,  " <<std::endl;
    std::cout<<"      __/   -*-  " <<std::endl;
    std::cout<<"    ,d08b.  '|`  " <<std::endl;
    std::cout<<"    0088MM      "<<std::endl;
    std::cout<<"    `9MMP'      " <<std::endl;

    // Case if vehicle type is Flying Car
    if (vehicleType == "Flying Car") {
        std::cout << "Actually we have to bomb your vehicle again because the car part is still survive >:(\n" << std::endl;
    } // Other type case 
    else {
        std::cout<< "Your " << vehicleType << " has been blown up :D" << std::endl;
    }
}

void Vehicle::setSpeed (){
    // Check whether Engine is already on
    if (!isEngineOn) {
        std::cout << "The engine is not turned on yet" << std::endl;
        return;
    }

    // DICTIONARY
    double newSpeed;

    // ALGORITHM
    // Asking input new speed
    std::cout << "New speed: "; std::cin >> newSpeed;

    // Invalid input
    if (newSpeed < 0) {
        std::cout << "Speed cannot be under 0" << std::endl;
    } else if (newSpeed > maxSpeed) {
        std::cout << "Your speed cannot exceed speed limit: " << maxSpeed << std::endl;
    } 
    // Valid input 
    else {
        speed = newSpeed;
        std::cout << "Speed has been changed to " << newSpeed << std::endl;
    }
}

void Vehicle::turnOnEngine(){
    // Check whether Engine is already on
    if (isEngineOn){
        std::cout << "Engine is already on" << std::endl;
        return;
    }
    // Assigning value to true
    isEngineOn = true;
    std::cout<<"Engine is turned on" << std::endl;
}

void Vehicle::move() {
    // Check whether Engine is already on
    if (!isEngineOn) {
        std::cout << "The engine is not turned on yet" << std::endl;
        return;
    }

    // Check whether speed is 0
    if (speed == 0) {
        std::cout << "Please set your speed > 0 first" << std::endl;
        return;
    }

    // DICTIONARY
    int x, y;

    // ALGORITHM
    // Asking input from user
    std::cout << "Please input how much you wanna go" << std::endl;
    std::cout << "X direction: "; std::cin >> x;
    std::cout << "Y direction: "; std::cin >> y;

    // Take absolute value
    int moveX = x, moveY = y;
    if (x < 0) { moveX = -x; }
    if (y < 0) { moveY = -y; }

    // Calculate loss fuel
    double loss = lossFuel(moveX,moveY); 
    
    // Not enough fuel case
    if (loss > fuelCapacity){
        std::cout << "Not enough fuel" << std::endl;
        return;
    } 
    // Valid case 
    else {
        absis += x;
        ordinat += y;
        fuelCapacity -= loss;
        std::cout << "You have moved to (" << absis << "," << ordinat << ")" << std::endl;
    }
}

void Vehicle::addPassanger() {
    // ALGORITHM
    // Valid case
    if (passanger < maxSeats){
        passanger += 1;
        std::cout << "Passanger has been added" << std::endl;
    } 
    // number of passanger = maximum seats case
    else {
        std::cout << "Seats are full" << std::endl;
    }
}

void Vehicle::printCommand() {
    // ALGORITHM
    // Display basic commands that can be performed
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
    // ALGORITHM
    // Display basic informations of the vehicle
    std::cout << "\n> Information <" << std::endl;
    std::cout << "1. Engine is " << (isEngineOn ? "on" : "off") <<std::endl;
    std::cout << "2. Speed: " << speed <<std::endl;
    std::cout << "3. Position: (" << absis << "," << ordinat << ")" <<std::endl;
    std::cout << "4. Fuel: " << fuelCapacity <<std::endl;
    std::cout << "5. Passanger: " << passanger << std::endl;
}

void Vehicle::printStats() {
    // ALGORITHM
    // Display basic statistics of the vehicle
    std::cout << "> " << vehicleType << " Statistics <" << std::endl;
    std::cout << "1. LossFuel : " << lossFuelFormula << std::endl;
    std::cout << "2. Maximum number of seats : " << maxSeats << std::endl;
    std::cout << "3. Maximum fuel capacity : " << maxFuel << std::endl;
    std::cout << "4. Maximum speed: " << maxSpeed << std::endl;
}

void Vehicle::refuel() {
    // ALGORITHM
    // Assigning fuel capacity to maximum fuel
    fuelCapacity = maxFuel;
    std::cout << "Your " << vehicleType << " has been refueled" << std::endl;
}

// =========================================================================================

LandVehicle::LandVehicle(int x,int y): Vehicle(x,y) {}
// Constructing LandVehicle object from Vehicle class

// =========================================================================================

Motorcycle::Motorcycle(int x, int y): LandVehicle(x,y) {
    // Construct Motocycle object from LandVehicle class

    // DICTIONARY
    char YN;

    // ALGORITHM
    // Asking user input
    std::cout << "Do you want your motorcycle to have helm storage? (Y/N) "; std::cin >> YN;
    while (YN != 'Y' and YN != 'N'){
        wrongInput();
        std::cout << "Do you want your motorcycle to have helm storage? (Y/N) "; std::cin >> YN;
    }
    hasHelmStorage = (YN == 'Y' ? true : false);

    // Display ASCII art
    std::cout << "\n" << std::endl;
    std::cout<< "   ,_o     " << std::endl;
    std::cout<< ".-/c-/,::  " << std::endl;
    std::cout<< "(_)'==(_)  " << std::endl;

    // Contructor message
    std::cout<< "Your motorcycle in (" << absis << "," << ordinat << ") ";
    if (hasHelmStorage) {
        std::cout << "with helm storage";
    } else {
        std::cout << "without helm storage";
    }
    std::cout << " has been magically created :D" <<std::endl;

    // Define attributes' value
    number_of_wheels = 2;
    maxSeats = 2;
    maxSpeed = 10;
    maxFuel = 500;
    lossFuelFormula = "0.5 * (speed*moveX + speed*moveY) * passanger";
    vehicleType = "Motorcycle";
}

void Motorcycle::addExternalHelmStorage(){
    // ALGORITHM
    // Check whether the motorcycle already has helm storage
    if (hasHelmStorage){
        std::cout << "Already has helm storage" << std::endl;
    } else {
        hasHelmStorage = true;
        std::cout << "External helm storage has been added" << std::endl;
    }
}

double Motorcycle::lossFuel(int moveX, int moveY) {
    // ALGORITHM
    // Return loss fuel calculation of Motorcycle class
    return 0.5*(speed*moveX + speed*moveY)*passanger;
}

void Motorcycle::printCommand(){
    // ALGORITHM
    // Call printCommand procedure from Vehicle class
    Vehicle::printCommand();
    
    // Display additional command from Motorcycle class
    std::cout << "8. Add external helm storage" << std::endl;
    std::cout << "0. Stop riding\n" << std::endl;
    std::cout << "Input yout choice: ";
}

void Motorcycle::printInformation() {
    // ALGORITHM
    // Call printInformation procedure from Vehicle class
    Vehicle::printInformation();

    // Display additional information from Motorcycle class
    std::cout << "6. Has helm storage: " << (hasHelmStorage ? "yes" : "no") <<std::endl;
}

void Motorcycle::addPassanger() {
    // ALGORITHM
    // Check whether the motorcycle has helm storage
    if (hasHelmStorage) {
        // Call addPassanger procedure from Vehicle class
        Vehicle::addPassanger();
    } else {
        std::cout << "Please add helm storage before add passanger" << std::endl;
    }
}

// =========================================================================================

Car::Car(int x, int y): LandVehicle(x,y) {
    // Construct Car object from LandVehicle class

    //ALGORITHM
    // Asking user input
    std::cout << "How many number of seats of your car: "; std::cin >> maxSeats;
    while (maxSeats < 1) {
        std::cout << "Your input is invalid, number of seats must be > 0" << std::endl;
        std::cout << "How many number of seats of your car: "; std::cin >> maxSeats;
    }

    // Display ASCII art
    std::cout << "\n" << std::endl;
    std::cout << "   ______         " << std::endl;
    std::cout << "  /|_||_\\`.__     " << std::endl;
    std::cout << " (   _    _ _\\    " << std::endl;
    std::cout << " =`-(_)--(_)-'    " << std::endl;

    // Display constructor message
    std::cout<< "Your car in (" << absis << "," << ordinat << ") with " << maxSeats << " number of seats has been magically created :D" << std::endl;
    
    // Define attributes' value
    number_of_wheels = 4;
    maxSpeed = 20;
    maxFuel = 2000;
    lossFuelFormula = "speed * (1.5) * (moveX + moveY) * (0.75 * passanger)";
    vehicleType = "Car";
}

double Car::lossFuel(int moveX, int moveY) { 
    // ALGORITHM
    // Return loss fuel calculation of Car class
    return (speed * (1.5) * (moveX + moveY) * (0.75 * passanger)); 
}

void Car::printCommand() {
    // ALGORITHM
    // Call printCommand() procedure from Vehicle class
    Vehicle::printCommand();

    // Display additional command from Car class
    std::cout << "8. Use NOS (increase max speed)" << std::endl;
    std::cout << "0. Stop driving\n" << std::endl;
    std::cout << "Input yout choice: ";
}

void Car::useNOS() {
    // ALGORITHM
    // Check whether the Car is already using NOS
    if (usingNOS) {
        std::cout << "You are already using NOS" << std::endl;
    } else {
        usingNOS = true;
        maxSpeed = 1.5 * maxSpeed;
        std::cout << "Your maximum speed now is " << maxSpeed << std::endl;
    }
}

// =========================================================================================

FlyingVehicle::FlyingVehicle(int x, int y): Vehicle(x,y) {}
// Constructing FlyingVehicle object from Vehicle class

void FlyingVehicle::printCommand() {
    // ALGORITHM
    // Call printCommand() from Vehicle class
    Vehicle::printCommand();

    // Display additional command from FlyingVehicle class
    std::cout << "8. Set your flying height" << std::endl;
}

void FlyingVehicle::printInformation() {
    // ALGORITHM
    // Call printInformation procedure from Vehicle class
    Vehicle::printInformation();

    // Display additional information from FlyingVehicle class
    std::cout << "7. Altitude: " << altitude << std::endl;
}

void FlyingVehicle::move() {
    // ALGORITHM
    // Check whether Plane altitude is already > 0
    if (altitude <= 0) {
        std::cout << "Your altitude must be > 0 first to move" << std::endl;
    } else {
        // Call move procedure from Vehicle class
        Vehicle::move();
    }
}

void FlyingVehicle::printStats() {
    // ALGORITHM
    // Call printStats procedure from Vehicle class
    Vehicle::printStats();

    // Display additional statistic from FlyingVehicle class
    std::cout << "5. Maximum altitude: " << maxAlti << std::endl;
}

void FlyingVehicle::setAltitude() {
    // DICTIONARY
    int newAltitude;

    // ALGORITHM
    // Asking user input
    std::cout << "New altitude: "; std::cin >> newAltitude;

    // Valid case
    if (newAltitude >= 0 && newAltitude <= maxAlti) {
        altitude = newAltitude;
        std::cout << "Your current altitude is " << newAltitude << std::endl;
    } 
    // Invalid case 
    else {
        std::cout << vehicleType << " altitude must be >= 0 and <= " << maxAlti << std::endl;
    }
}

// =========================================================================================

Plane::Plane(int x, int y): FlyingVehicle(x,y) {
    // Construct Plane object from FlyingVehicle class

    // DICTIONARY
    int choice;

    // ALGORITHM
    std::cout << "Please choose your plane" << std::endl;
    std::cout << "1. Boeing (number of seats: 7.000, max fuel capacity: 80.000)" << std::endl;
    std::cout << "2. Airbus (number of seats: 10.000, max fuel capacity: 100.000)" << std::endl;
    std::cout << "3. Customize (number of seats & max fuel capacity are customizable)" << std::endl;
    
    while (true) {
        // Asking user input
        std::cout << "Input your choice: "; std::cin >> choice;
        
        // Case 1
        if (choice == 1) {
            PlaneType = "Boeing";
            maxSeats = 7000;
            maxFuel = 80000;
            break;
        } 
        // Case 2
        else if (choice == 2) {
            PlaneType = "Airbus";
            maxSeats = 10000;
            maxFuel = 100000;
            break;
        } 
        // Case 3
        else if (choice == 3) {
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
        } 
        // Default case
        else {
            wrongInput();
        }
    }

    while (true) {
        // Asking user input
        std::cout << "Please input your number of engines: "; std::cin >> number_of_engine;
        if (number_of_engine <= 1) {
            std::cout << "Number of engine must be > 1\n" << std::endl;
        } else {
            break;
        }
    }

    // Display ASCII art
    std::cout << "\n" << std::endl;
    std::cout << "       __|__          " << std::endl;
    std::cout << "--------(_)--------   " << std::endl;
    std::cout << "  O  O       O  O     " << std::endl;

    // Display constructor message
    std::cout << "\nYour " << PlaneType << " plane with " << number_of_engine << " number of engines and " << maxSeats << " number of seats has been magically created :D" << std::endl;

    // Define attributes' value
    maxAlti = 20000;
    maxSpeed = 100;
    lossFuelFormula = "2 * speed * (moveX + moveY) * (0.5 * passanger) * ((25.000 - altitude) / 10.000)";
    vehicleType = "Plane";
}

void Plane::printCommand() {
    // ALGORITHM
    // Call printCommand() procedure from FlyingVehicle class
    FlyingVehicle::printCommand();

    // Display additional command from Plane class
    std::cout << "0. Stop flying\n" << std::endl;
    std::cout << "Input yout choice: ";
}

double Plane::lossFuel(int moveX, int moveY) {
    // ALGORITHM
    // Return loss fuel calculation of Plane class
    return 2 * speed * (moveX + moveY) * (1+ 0.1*passanger) * ((25000 - altitude) / 10000);
}

void Plane::addPassanger() {
    // DICTIONARY
    int added;

    // ALGORITHM
    // Asking user input
    std::cout << "Input how many added passanger: "; std::cin >> added;
    
    // Invalid input case
    if (added < 0) {
        wrongInput();
        return;
    }
    // Valid input case
    if ((added + passanger) <= maxSeats) {
        passanger += added;
        std::cout << added << " passanger has been added" << std::endl;
    } 
    // Added passanger > rest of the seats case 
    else {
        std::cout << "Seats are full, with passanger: " << passanger << " and max seats: " << maxSeats << std::endl; 
    }
}

// =========================================================================================

Helicopter::Helicopter(int x, int y): FlyingVehicle(x,y) {
    // Construct Helicopter object from FlyingVehicle class

    while (true) {
        // Asking user input
        std::cout << "Please input your number of blades: "; std::cin >> number_of_blade;
        
        // Invalid input case
        if (number_of_blade <= 0) {
            std::cout << "Number of engine must be > 0\n" << std::endl;
        } 
        // Valid input case
        else {
            break;
        }
    }

    // Display ASCII art
    std::cout << "\n" << std::endl;
    std::cout << "   -----|-----    " << std::endl;
    std::cout << "*>=====[_]L)      " << std::endl;
    std::cout << "      -'-`-       " << std::endl;
    
    // Display constuctor message
    std::cout << "Your helicopter with " << number_of_blade << " number of blades has been magically created :D" << std::endl;

    // Define attributes' value
    maxSpeed = 40;
    maxFuel = 5000;
    maxAlti = 4000;
    maxSeats = 4;
    lossFuelFormula = "2 * speed * (moveX + moveY) * (0.5 * passanger) * ((25.000 - altitude) / 10.000)";
    vehicleType = "Helicopter";
}

double Helicopter::lossFuel(int moveX, int moveY) {
    // ALGORITHM
    // Return loss fuel calculation of Helicopter class
    return (speed * (1.75) * (moveX + moveY) * (1 + passanger) + (5000 - altitude)/1000); 
}

void Helicopter::printCommand() {
    // ALGORITHM
    // Call printCommand() procedure from FlyingVehicle class
    FlyingVehicle::printCommand();

    // Display additional command from Car class    
    std::cout << "0. Stop flying\n" << std::endl;
    std::cout << "Input yout choice: ";
}

// =========================================================================================

FlyingCar::FlyingCar(int x, int y): Car(x,y), FlyingVehicle(x,y) {
    // Construct FlyingCar object from Car and FlyingVehicle class

    // ALGORITHM
    // Define attributes' value
    FlyingVehicle::maxSeats = Car::maxSeats;
    number_of_wheels = 4;
    FlyingVehicle::maxSpeed = 50;
    FlyingVehicle::maxFuel = 2000;
    maxAlti = 5000;
    FlyingVehicle::vehicleType = "Flying Car";
    FlyingVehicle::lossFuelFormula = "(speed * (1.5) * (moveX + moveY) * (0.75 * passanger)) * (1 - (altitude/(2 * maxAltitude))";
}

void FlyingCar::flying(){
    // ALGORITHM
    // Check whether FlyingCar is already flying
    if (isFlying) {
        std::cout << "You are already flying" << std::endl;
    } else {
        isFlying = true;
        std::cout << "Now you are flying" << std::endl;
    }
}

void FlyingCar::landing(){
    // ALGORITHM
    // Check whether FlyingCar is already on the road
    if (!isFlying) {
        std::cout << "You are already on the road" << std::endl;
    } else {
        isFlying = true;
        altitude = 0;
        std::cout << "Now you are on the road" << std::endl;
    }
}

void FlyingCar::printCommand() {
    // ALGORITHM
    // Call printCommand() procedure from Vehicle class
    FlyingVehicle::printCommand();

    // Display additional command from FlyingCar class
    std::cout << "9. Start flying" << std::endl;
    std::cout << "10. Use land road" << std::endl;
    std::cout << "11. Use NOS" << std::endl;
    std::cout << "0. Stop travelling\n" << std::endl;
    std::cout << "Input yout choice: ";
}

double FlyingCar::lossFuel(int moveX, int moveY) {
    // ALGORITHM
    // Return loss fuel calculation of Car class
    return (FlyingVehicle::speed * (1.5) * (moveX + moveY) * (0.75 * FlyingVehicle::passanger)) * (1 - (altitude/(2*maxAlti)));     
}

void FlyingCar::setAltitude(){
    // ALGORITHM
    // Check whether FlyingCar is already flying
    if (isFlying) {
        // Call setAltitude() procedure from FlyingVehicle class
        FlyingVehicle::setAltitude();
    } else {
        std::cout << "You must start flying first" << std::endl;
    }
}

void FlyingCar::useNOS() {
    // ALGORITHM
    // Check whether the Car is already using NOS
    if (usingNOS) {
        std::cout << "You are already using NOS" << std::endl;
    } else {
        usingNOS = true;
        FlyingVehicle::maxSpeed = FlyingVehicle::maxSpeed * 1.5;
        std::cout << "Your maximum speed now is " << FlyingVehicle::maxSpeed << std::endl;
    }
}

// =========================================================================================

void wrongInput(){
    // Display invalid input message
    std::cout << "Your input is invalid!" << std::endl;
}