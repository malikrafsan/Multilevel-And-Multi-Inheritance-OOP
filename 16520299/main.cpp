#include <iostream>

class Vehicle {
    protected:
        int number_of_wheels;
        double fuelCapacity = 0;
        bool isEngineOn = false;
        double speed = 0;
        int absis, ordinat;
    
    public:
        Vehicle() { 
            std::cout<< "Vehicle has been constructed" << std::endl; 
        }
        
        Vehicle(int x, int y) { 
            absis = x;
            ordinat = y;
        }
        ~Vehicle() { 
            std::cout<< "Vehicle has been deleted" << std::endl;
        }

        double getVelocity(){
            return speed;
        }

        void setSpeed (double newSpeed){
            if (!isEngineOn) {
                std::cout << "The engine is not turned on yet" << std::endl;
                return;
            }

            if (newSpeed < 0) {
                std::cout << "Speed cannot be under 0" << std::endl;
            } else {
                speed = newSpeed;
                std::cout << "Speed has been changed to " << newSpeed << std::endl;
            }
        }

        void turnOnEngine(){
            if (isEngineOn){
                std::cout << "Engine is already on" << std::endl;
                return;
            }
            isEngineOn = true;
            std::cout<<"Engine is turned on" << std::endl;
        }

        void moving(int x, int y, double lossFuel) {
            absis += x;
            ordinat += y;
            fuelCapacity -= lossFuel;
            std::cout << "You have moved to (" << absis << "," << ordinat << ")" << std::endl;
        }

        virtual void move(int x, int y) = 0;
        virtual void refuel() = 0;
        virtual void printStats() = 0;
        virtual void printCommand() = 0;
        virtual void printInformation() = 0;
};

class Motorcycle : public Vehicle {
    private:
        bool hasHelmStorage;
    public:
        Motorcycle(int x, int y, bool helmStorage): Vehicle(x,y) {
            hasHelmStorage = helmStorage;
            std::cout<< "Motorcycle in (" << absis << "," << ordinat << ") has been constructed ";
            if (hasHelmStorage) {
                std::cout << "with helm storage" <<std::endl;
            } else {
                std::cout << "without helm storage" << std::endl;
            }
        }

        void addExternalHelmStorage(){
            if (hasHelmStorage){
                std::cout << "Already has helm storage" << std::endl;
            } else {
                hasHelmStorage = true;
                std::cout << "External helm storage has been added" << std::endl;
            }
        }

        void move(int x, int y) {
            if (!isEngineOn) {
                std::cout << "The engine is not turned on yet" << std::endl;
                return;
            }

            if (speed == 0) {
                std::cout << "Please set your speed > 0 first" << std::endl;
                return;
            }

            int moveX = x, moveY = y;
            if (x < 0) { moveX = -x; }
            if (y < 0) { moveY = -y; }
            double lossFuel = 0.5*(speed*moveX + speed*moveY); 
            
            if (lossFuel > fuelCapacity){
                std::cout << "Not enough fuel" << std::endl;
                return;
            } else {
                moving(x,y,lossFuel);
            }
        }

        void refuel() {
            fuelCapacity = 500;
            std::cout << "Your vehicle has been refueled" << std::endl;
        }

        void printStats(){
            std::cout << "Motorcycle Statistics:" << std::endl;
            std::cout << "1. LossFuel : 0.5*(speed*x + speed*y)" << std::endl;
        }

        void printCommand(){
            std::cout << "Motorcycle command: " << std::endl;
            std::cout << "1. Turn on engine" << std::endl;
            std::cout << "2. Set speed" << std::endl;
            std::cout << "3. Move" << std::endl;
            std::cout << "4. Refuel" << std::endl;
            std::cout << "5. Add external helm storage" << std::endl;
            std::cout << "6. Display information" << std::endl;
            std::cout << "0. Stop riding\n" << std::endl;
            std::cout << "Input yout choice: ";
        }

        void printInformation() {
            std::cout << "\n> Information <" << std::endl;
            std::cout << "1. Engine is " << (isEngineOn ? "on" : "off") <<std::endl;
            std::cout << "2. Speed: " << speed <<std::endl;
            std::cout << "3. Position: (" << absis << "," << ordinat << ")" <<std::endl;
            std::cout << "4. Fuel: " << fuelCapacity <<std::endl;
            std::cout << "5. Helm storage: " << (hasHelmStorage ? "yes" : "no") <<std::endl;
        }
};

void wrongInput(){
    std::cout << "Your input is invalid!" << std::endl;
}

int main(){
    int absis, ordinat;
    double speed;

    std::cout << "Please input your position" << std::endl;
    std::cout << "Absis: "; std::cin >> absis;
    std::cout << "Ordinat: "; std::cin >> ordinat;

    int choice;
    std::cout << "\nChoose your vehicle" << std::endl;
    std::cout << "1. Motorcycle" << std::endl;
    std::cout << "\nInput your choice: "; std::cin >> choice;

    // Use if-else if because cannot initialize class inside switch
    if (choice == 1){
        Motorcycle bike = Motorcycle(absis,ordinat,false);
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
                bike.addExternalHelmStorage();
                break;

            case 6:
                bike.printInformation();
                break;

            default:
                wrongInput();
                break;
            }
            std::cout <<"\n===================\n" << std::endl;
        } while (true);
    } else{
        // Has not implemented
    }
}

// std::cout << "" << std::endl;
/*
    Motorcycle myBike = Motorcycle(5, 0, false);
    
    myBike.setVelocity(20);
    std::cout << "Velocity: " << myBike.getVelocity() << std::endl;
*/