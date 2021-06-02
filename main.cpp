#include <iostream>
#include "class.hpp"

int main(){
    // DICTIONARY
    int absis, ordinat, choice;
    double speed;

    // ALGORITHM
    std::cout << "Welcome to Simple C++ OOP program\n" << std::endl;
    
    // Ask user input about position
    std::cout << "Please input your position" << std::endl;
    std::cout << "Absis: "; std::cin >> absis;
    std::cout << "Ordinat: "; std::cin >> ordinat;

    // Display vehicle menu
    std::cout << "\nChoose your vehicle" << std::endl;
    std::cout << "1. Motorcycle" << std::endl;
    std::cout << "2. Car" << std::endl;
    std::cout << "3. Plane" << std::endl;
    std::cout << "4. Helicopter" << std::endl;
    std::cout << "5. Flying Car" << std::endl;

    // Ask user input about vehicle choice
    std::cout << "\nInput your choice: "; std::cin >> choice;

    // Using if-else if because cannot initialize class inside switch
    // Motorcycle case
    if (choice == 1){
        // Object declaration
        Motorcycle bike = Motorcycle(absis,ordinat);
        std::cout << std::endl;

        do {
            // Display commands that can be performed
            bike.printCommand();
            std::cin >> choice;
            
            // Exit program case
            if (choice == 0) {
                std::cout << "\nBut before exit the program :D" << std::endl; 
                break;
            }
            switch (choice){
                // Turn on engine command case
                case 1:
                    bike.turnOnEngine();
                    break;

                // Set speed command case
                case 2:
                    bike.setSpeed();
                    break;

                // Move command case
                case 3:
                    bike.move();
                    break;

                // Refuel command case
                case 4:
                    bike.refuel();
                    break;

                // Add passanger command case
                case 5:
                    bike.addPassanger();
                    break;

                // Display information command case
                case 6:
                    bike.printInformation();
                    break;

                // Display Motorcycle statistics command case
                case 7:
                    bike.printStats();
                    break;

                // Add external helm storage command case
                case 8:
                    bike.addExternalHelmStorage();
                    break;
                
                // Invalid input case
                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    // Car case
    } else if (choice == 2) {
        // Object declaration
        Car myCar = Car(absis,ordinat);
        std::cout << std::endl;

        do {
            // Display commands that can be performed
            myCar.printCommand();
            std::cin >> choice;
            
            // Exit program case
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                // Turn on engine command case
                case 1:
                    myCar.turnOnEngine();
                    break;

                // Set speed command case
                case 2:
                    myCar.setSpeed();
                    break;

                // Move command case
                case 3:
                    myCar.move();
                    break;

                // Refuel command case
                case 4:
                    myCar.refuel();
                    break;

                // Add passanger command case
                case 5:
                    myCar.addPassanger();
                    break;

                // Display information command case
                case 6:
                    myCar.printInformation();
                    break;

                // Display Car statistics command case
                case 7:
                    myCar.printStats();
                    break;

                // Use NOS (increase max speed) command case
                case 8:
                    myCar.useNOS();
                    break;

                // Invalid input case
                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    // Plane case
    } else if (choice == 3) {
        // Object declaration
        Plane myPlane = Plane(absis, ordinat);
        std::cout << std::endl;

        do {
            // Display commands that can be performed
            myPlane.printCommand();
            std::cin >> choice;
            
            // Exit program case
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                // Turn on engine command case
                case 1:
                    myPlane.turnOnEngine();
                    break;

                // Set speed command case
                case 2:
                    myPlane.setSpeed();
                    break;

                // Move command case
                case 3:
                    myPlane.move();
                    break;

                // Refuel command case
                case 4:
                    myPlane.refuel();
                    break;

                // Add passanger command case
                case 5:
                    myPlane.addPassanger();
                    break;

                // Display information command case
                case 6:
                    myPlane.printInformation();
                    break;

                // Display Plane statistics command case
                case 7:
                    myPlane.printStats();
                    break;

                // Set your flying height command case
                case 8:
                    myPlane.setAltitude();
                    break;

                // Invalid input case
                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    // Helicopter case
    } else if (choice == 4) {
        // Object declaration
        Helicopter myHeli = Helicopter(absis, ordinat);
        std::cout << std::endl;

        do {
            // Display commands that can be performed
            myHeli.printCommand();
            std::cin >> choice;
            
            // Exit program case
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                // Turn on engine command case
                case 1:
                    myHeli.turnOnEngine();
                    break;

                // Set speed command case
                case 2:
                    myHeli.setSpeed();
                    break;

                // Move command case
                case 3:
                    myHeli.move();
                    break;

                // Refuel command case
                case 4:
                    myHeli.refuel();
                    break;

                // Add passanger command case
                case 5:
                    myHeli.addPassanger();
                    break;

                // Display information command case
                case 6:
                    myHeli.printInformation();
                    break;

                // Display Helicopter statistics command case
                case 7:
                    myHeli.printStats();
                    break;

                // Set your flying height command case
                case 8:
                    myHeli.setAltitude();
                    break;

                // Invalid input case
                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);
    
    // Flying Car case
    } else if (choice == 5) {
        // Object declaration
        FlyingCar myFlyingCar = FlyingCar(absis, ordinat);
        std::cout << std::endl;

        do {
            // Display commands that can be performed
            myFlyingCar.printCommand();
            std::cin >> choice;

            // Exit program case
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                // Turn on engine command case
                case 1:
                    myFlyingCar.FlyingVehicle::turnOnEngine();
                    break;

                // Set speed command case
                case 2:
                    myFlyingCar.FlyingVehicle::setSpeed();
                    break;

                // Move command case
                case 3:
                    myFlyingCar.FlyingVehicle::move();
                    break;

                // Refuel command case
                case 4:
                    myFlyingCar.FlyingVehicle::refuel();
                    break;

                // Refuel command case
                case 5:
                    myFlyingCar.FlyingVehicle::addPassanger();
                    break;

                // Add passanger command case
                case 6:
                    myFlyingCar.FlyingVehicle::printInformation();
                    break;

                // Display information command case
                case 7:
                    myFlyingCar.FlyingVehicle::printStats();
                    break;

                // Display Flying Car statistics command case
                case 8:
                    myFlyingCar.setAltitude();
                    break;

                // Start flying command case
                case 9:
                    myFlyingCar.flying();
                    break;

                // Use land road command case
                case 10:
                    myFlyingCar.landing();
                    break;

                // Use NOS command case
                case 11:
                    myFlyingCar.useNOS();
                    break;

                // Invalid input case
                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    // Invalid input case
    } else {
        wrongInput();
        std::cout << std::endl;
        // Recursive method
        main();
    }
}