#include <iostream>

class Car
{
    private:
        bool isIgnitionOn;
        int speed;
    public:
        void turnIgnitionOn() { isIgnitionOn = true; };
        void turnIgnitionOff() { isIgnitionOn = false; };
        void setSpeed(int mph) { speed = mph; };
        void showCar();
};

void Car::showCar()
{
    std::cout << "at " << speed << " mph: Ignition is ";
    if (isIgnitionOn) std::cout << "on. ";
    else std::cout << "off. ";
    std::cout << "Speed is " << speed << std::endl;
}

class Convertible : public Car
{
    private:
        bool isTopUp;
    public:
        void putTopUp() { isTopUp = true; };
        void putTopDown() { isTopUp = false; };
        void showCar() { Car::showCar(); };
};

class RaceCar : public Car
{
    public:
        void setSpeed(int mph) { Car::setSpeed(mph); };
};

class ConvertibleRaceCar : public Convertible, public RaceCar
{
};

int main()
{
    Car normalCar;
    ConvertibleRaceCar convertibleCar;
    RaceCar raceCar;

    normalCar.setSpeed(80);
    normalCar.turnIgnitionOn();

    raceCar.setSpeed(120);
    raceCar.turnIgnitionOn();

    std::cout << "Car "; normalCar.showCar();
    std::cout << "Race car "; raceCar.showCar();
}