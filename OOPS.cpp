#include <iostream>
using namespace std;

// Abstraction + Encapsulation
class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }

    // Encapsulation: Getters and Setters
    string getBrand() { return brand; }
    void setBrand(string b) { brand = b; }

    int getSpeed() { return speed; }
    void setSpeed(int s) { speed = s; }

    // Abstraction: Virtual Function
    virtual void displayInfo() = 0;

    virtual ~Vehicle() {}
};

// Inheritance + Abstraction continued
class Car : public Vehicle {
private:
    string model;

public:
    Car(string b, int s, string m) : Vehicle(b, s), model(m) {}

    void displayInfo() override {
        cout << "Car Brand: " << brand << ", Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }

    // Compile-Time Polymorphism (Overloading)
    void accelerate() {
        speed += 10;
        cout << "Accelerated by 10 km/h. Current speed: " << speed << " km/h" << endl;
    }

    void accelerate(int increment) {
        speed += increment;
        cout << "Accelerated by " << increment << " km/h. Current speed: " << speed << " km/h" << endl;
    }
};

// Another class to show Run-Time Polymorphism
class ElectricCar : public Car {
public:
    ElectricCar(string b, int s, string m) : Car(b, s, m) {}

    void displayInfo() override {
        cout << "Electric Car Brand: " << getBrand() << ", Speed: " << getSpeed() << " km/h" << endl;
    }
};

int main() {
    Car c1("Toyota", 100, "Fortuner");
    c1.displayInfo();
    c1.accelerate();
    c1.accelerate(25);

    // Polymorphism: base class pointer to derived object
    Vehicle* v = new ElectricCar("Tesla", 120, "Model S");
    v->displayInfo();

    delete v;
    return 0;
}