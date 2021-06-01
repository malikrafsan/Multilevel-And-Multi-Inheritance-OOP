#include <iostream>
#include "class.hpp"

int main(){
    int absis, ordinat, altitude;
    double speed;

    std::cout << "Please input your position" << std::endl;
    std::cout << "Absis: "; std::cin >> absis;
    std::cout << "Ordinat: "; std::cin >> ordinat;

    int choice;
    std::cout << "\nChoose your vehicle" << std::endl;
    std::cout << "1. Motorcycle" << std::endl;
    std::cout << "2. Car" << std::endl;
    std::cout << "3. Plane" << std::endl;
    std::cout << "4. Helicopter" << std::endl;
    std::cout << "\nInput your choice: "; std::cin >> choice;

    // Use if-else if because cannot initialize class inside switch
    if (choice == 1){
        Motorcycle bike = Motorcycle(absis,ordinat);
        std::cout << std::endl;

        do {
            bike.printCommand();
            std::cin >> choice;
            
            if (choice == 0) {
                std::cout << "\nExit the program" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    bike.turnOnEngine();
                    break;

                case 2:
                    std::cout << "New speed: "; std::cin >> speed;
                    bike.setSpeed(speed);
                    break;

                case 3:
                    std::cout << "Please input how much you wanna go" << std::endl;
                    std::cout << "X direction: "; std::cin >> absis;
                    std::cout << "Y direction: "; std::cin >> ordinat;
                    bike.move(absis,ordinat);
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
                std::cout << "\nExit the program" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    myCar.turnOnEngine();
                    break;

                case 2:
                    std::cout << "New speed: "; std::cin >> speed;
                    myCar.setSpeed(speed);
                    break;

                case 3:
                    std::cout << "Please input how much you wanna go" << std::endl;
                    std::cout << "X direction: "; std::cin >> absis;
                    std::cout << "Y direction: "; std::cin >> ordinat;
                    myCar.move(absis,ordinat);
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
                std::cout << "\nExit the program" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    myPlane.turnOnEngine();
                    break;

                case 2:
                    std::cout << "New speed: "; std::cin >> speed;
                    myPlane.setSpeed(speed);
                    break;

                case 3:
                    std::cout << "Please input how much you wanna go" << std::endl;
                    std::cout << "X direction: "; std::cin >> absis;
                    std::cout << "Y direction: "; std::cin >> ordinat;
                    myPlane.move(absis,ordinat);
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
                    std::cout << "New altitude: "; std::cin >> altitude;
                    myPlane.setAltitude(altitude);
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
                std::cout << "\nExit the program" << std::endl; 
                break;
            }

            switch (choice){
                case 1:
                    myHeli.turnOnEngine();
                    break;

                case 2:
                    std::cout << "New speed: "; std::cin >> speed;
                    myHeli.setSpeed(speed);
                    break;

                case 3:
                    std::cout << "Please input how much you wanna go" << std::endl;
                    std::cout << "X direction: "; std::cin >> absis;
                    std::cout << "Y direction: "; std::cin >> ordinat;
                    myHeli.move(absis,ordinat);
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
                    std::cout << "New altitude: "; std::cin >> altitude;
                    myHeli.setAltitude(altitude);
                    break;

                default:
                    wrongInput();
                    break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);
        
    } else {
        wrongInput();
        std::cout << "\n" << std::endl;
        main();
    }
}