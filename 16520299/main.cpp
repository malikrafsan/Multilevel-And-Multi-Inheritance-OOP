#include <iostream>
#include "class.hpp"

int main(){
    int absis, ordinat;
    double speed;

    std::cout << "Please input your position" << std::endl;
    std::cout << "Absis: "; std::cin >> absis;
    std::cout << "Ordinat: "; std::cin >> ordinat;

    int choice;
    std::cout << "\nChoose your vehicle" << std::endl;
    std::cout << "1. Motorcycle" << std::endl;
    std::cout << "2. Car" << std::endl;
    std::cout << "\nInput your choice: "; std::cin >> choice;

    // Use if-else if because cannot initialize class inside switch
    if (choice == 1){
        char YN; bool hasHelmStorage;
        std::cout << "Do you want your motorcycle to have helm storage? (Y/N) "; std::cin >> YN;
        while (YN != 'Y' and YN != 'N'){
            wrongInput();
            std::cout << "Do you want your motorcycle to have helm storage? (Y/N) "; std::cin >> YN;
        }

        Motorcycle bike = Motorcycle(absis,ordinat,(YN == 'Y' ? true : false));
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
    } else {
        wrongInput();
    }
}