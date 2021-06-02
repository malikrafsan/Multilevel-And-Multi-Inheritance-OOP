#include <iostream>
#include "class.hpp"

int main(){
    int absis, ordinat, choice;
    double speed;

    std::cout << "Welcome to Simple C++ OOP program\n" << std::endl;
    std::cout << "Please input your position" << std::endl;
    std::cout << "Absis: "; std::cin >> absis;
    std::cout << "Ordinat: "; std::cin >> ordinat;

    std::cout << "\nChoose your vehicle" << std::endl;
    std::cout << "1. Motorcycle" << std::endl;
    std::cout << "2. Car" << std::endl;
    std::cout << "3. Plane" << std::endl;
    std::cout << "4. Helicopter" << std::endl;
    std::cout << "5. Flying Car" << std::endl;
    std::cout << "\nInput your choice: "; std::cin >> choice;

    // Use if-else if because cannot initialize class inside switch
    if (choice == 1){
        // Object declaration
        Motorcycle bike = Motorcycle(absis,ordinat);
        std::cout << std::endl;

        do {
            bike.printCommand();
            std::cin >> choice;
            
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }
            switch (choice){
                case 1:
                    bike.turnOnEngine();
                    break;

                case 2:
                    bike.setSpeed();
                    break;

                case 3:
                    bike.move();
                    break;

                case 4:
                    bike.refuel();
                    break;

                case 5:
                    bike.addPassanger();
                    break;

                case 6:
                    bike.printInformation();
                    break;

                case 7:
                    bike.printStats();
                    break;

                case 8:
                    bike.addExternalHelmStorage();
                    break;

                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    } else if (choice == 2) {
        Car myCar = Car(absis,ordinat);
        std::cout << std::endl;

        do {
            myCar.printCommand();
            std::cin >> choice;
            
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    myCar.turnOnEngine();
                    break;

                case 2:
                    myCar.setSpeed();
                    break;

                case 3:
                    myCar.move();
                    break;

                case 4:
                    myCar.refuel();
                    break;

                case 5:
                    myCar.addPassanger();
                    break;

                case 6:
                    myCar.printInformation();
                    break;

                case 7:
                    myCar.printStats();
                    break;

                case 8:
                    myCar.useNOS();
                    break;

                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    } else if (choice == 3) {
        Plane myPlane = Plane(absis, ordinat);
        std::cout << std::endl;

        do {
            myPlane.printCommand();
            std::cin >> choice;
            
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    myPlane.turnOnEngine();
                    break;

                case 2:
                    myPlane.setSpeed();
                    break;

                case 3:
                    myPlane.move();
                    break;

                case 4:
                    myPlane.refuel();
                    break;

                case 5:
                    myPlane.addPassanger();
                    break;

                case 6:
                    myPlane.printInformation();
                    break;

                case 7:
                    myPlane.printStats();
                    break;

                case 8:
                    myPlane.setAltitude();
                    break;

                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    } else if (choice == 4) {
        Helicopter myHeli = Helicopter(absis, ordinat);
        std::cout << std::endl;

        do {
            myHeli.printCommand();
            std::cin >> choice;
            
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    myHeli.turnOnEngine();
                    break;

                case 2:
                    myHeli.setSpeed();
                    break;

                case 3:
                    myHeli.move();
                    break;

                case 4:
                    myHeli.refuel();
                    break;

                case 5:
                    myHeli.addPassanger();
                    break;

                case 6:
                    myHeli.printInformation();
                    break;

                case 7:
                    myHeli.printStats();
                    break;

                case 8:
                    myHeli.setAltitude();
                    break;

                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);
        
    } else if (choice == 5) {
        FlyingCar myFlyingCar = FlyingCar(absis, ordinat);
        std::cout << std::endl;

        do {
            myFlyingCar.printCommand();
            std::cin >> choice;
            
            if (choice == 0) {
                std::cout << "\nBefore exit the program :D" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    myFlyingCar.FlyingVehicle::turnOnEngine();
                    break;

                case 2:
                    myFlyingCar.FlyingVehicle::setSpeed();
                    break;

                case 3:
                    myFlyingCar.FlyingVehicle::move();
                    break;

                case 4:
                    myFlyingCar.FlyingVehicle::refuel();
                    break;

                case 5:
                    myFlyingCar.FlyingVehicle::addPassanger();
                    break;

                case 6:
                    myFlyingCar.FlyingVehicle::printInformation();
                    break;

                case 7:
                    myFlyingCar.FlyingVehicle::printStats();
                    break;

                case 8:
                    myFlyingCar.setAltitude();
                    break;

                case 9:
                    myFlyingCar.flying();
                    break;

                case 10:
                    myFlyingCar.landing();
                    break;

                case 11:
                    myFlyingCar.useNOS();
                    break;

                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);

    } else {
        wrongInput();
        std::cout << std::endl;
        main();
    }
}