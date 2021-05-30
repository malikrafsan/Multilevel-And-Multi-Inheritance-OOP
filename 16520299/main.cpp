#include <iostream>

class Vehicle {
    protected:
        int number_of_wheels;
        double status_of_the_fuel;
        bool status_of_engine;
        double velocity;
        int absis, ordinat;
    
    public:
        Vehicle() { 
            std::cout<< "Vehicle has been constructed" << std::endl; 
        }
        
        Vehicle(int x, int y, double speed) { 
            absis = x;
            ordinat = y;
            velocity = speed;
        }
        ~Vehicle() { 
            std::cout<< "Vehicle has been deleted" << std::endl;
        }

        double getVelocity(){
            return velocity;
        }

        void setVelocity(double newVelocity){
            velocity = newVelocity;
        }

        virtual void accelerate() = 0;
};

class Motorcycle : public Vehicle {
    private:
        bool hasHelmStorage;

    public:
        Motorcycle(int x, int y, double speed, bool helmStorage): Vehicle(x,y,speed) {
            hasHelmStorage = helmStorage;
            std::cout<< "Motorcycle in (" << absis << "," << ordinat << ") has been constructed with velocity: " << velocity << std::endl;
        }
        void addExternalHelmStorage(){
            if (hasHelmStorage){
                std::cout << "Already has helm storage" << std::endl;
            }
        }

        void accelerate() {
            // isnt implemented yet
            std::cout << "Accelerated" << std::endl;
        }
};

int main(){
    Motorcycle myBike = Motorcycle(5, 0, 10, false);
    
    myBike.setVelocity(20);
    std::cout << "Velocity: " << myBike.getVelocity() << std::endl;
}