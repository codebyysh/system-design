#include <iostream>
#include <string>

using namespace std;

// 1. Class and Object

//   * A Class is a blueprint or a template for creating objects.
//   * An Object is an instance of a class.

class Vehicle { // Base class (general concept of a vehicle)
private:
    string model;
    string color;
    int year;

public:
    // Constructor (to initialize objects)
    Vehicle(string m, string c, int y) : model(m), color(c), year(y) {}

    // Method to display vehicle info
    void displayInfo() {
        cout << "Model: " << model << ", Color: " << color << ", Year: " << year << endl;
    }

    // Method to simulate basic movement (can be overridden)
    void move() {
        cout << "The vehicle is moving." << endl;
    }
};

int main() {
    // Creating objects of the Vehicle class
    Vehicle myCar("Sedan", "Blue", 2022);
    Vehicle myBike("Mountain Bike", "Black", 2021);

    myCar.displayInfo(); // Output: Model: Sedan, Color: Blue, Year: 2022
    myBike.displayInfo(); // Output: Model: Mountain Bike, Color: Black, Year: 2021

    myCar.move(); // Output: The vehicle is moving.
    myBike.move(); // Output: The vehicle is moving.

    // 2. Inheritance

    //   * Inheritance allows you to create new classes (derived or child classes)
    //       based on existing classes (base or parent classes).
    //   * It promotes code reusability and establishes a "is-a-kind-of" relationship.

    class Car : public Vehicle { // Car "is a kind of" Vehicle
    private:
        int numberOfDoors;

    public:
        // Constructor (calls Vehicle's constructor)
        Car(string m, string c, int y, int doors) : Vehicle(m, c, y), numberOfDoors(doors) {}

        void displayCarInfo() {
            displayInfo(); // Inherited from Vehicle
            cout << "Number of Doors: " << numberOfDoors << endl;
        }

        // Overriding the move() method (Polymorphism)
        void move() {
            cout << "The car is driving on the road." << endl; // More specific behavior
        }
    };

    class Bicycle : public Vehicle { // Bicycle "is a kind of" Vehicle
    private:
        int numberOfGears;

    public:
        Bicycle(string m, string c, int y, int gears) : Vehicle(m, c, y), numberOfGears(gears) {}

        void displayBicycleInfo() {
            displayInfo(); // Inherited from Vehicle
            cout << "Number of Gears: " << numberOfGears << endl;
        }

        // Overriding the move() method (Polymorphism)
        void move() {
            cout << "The bicycle is pedaling along the path." << endl; // More specific behavior
        }
    };

    Car mySportsCar("Sports Car", "Red", 2023, 2);
    Bicycle myRoadBike("Road Bike", "Silver", 2022, 21);

    mySportsCar.displayCarInfo();
    myRoadBike.displayBicycleInfo();

    mySportsCar.move(); // Output: The car is driving on the road.
    myRoadBike.move(); // Output: The bicycle is pedaling along the path.

    // 3. Polymorphism

    //   * Polymorphism means "many forms."
    //   * It allows objects of different classes to respond to the same method call
    //       in their own specific ways.
    //   * This is often achieved through method overriding (as seen in the `move()` method).

    //   * In the example above, even though both `mySportsCar` and `myRoadBike` are called with the `move()`
    //       method, they behave differently.

    // 4. Encapsulation

    //   * Encapsulation is the bundling of data (attributes) and methods that operate on that data
    //       within a single unit (a class).
    //   * It also involves controlling access to the data (using access modifiers like `private` and `public`)
    //       to prevent unauthorized modification.

    //   * In the `Vehicle` class:
    //       * `model`, `color`, and `year` are `private`: They can only be accessed from within the `Vehicle` class.
    //       * `displayInfo()` and `move()` are `public`: They can be accessed from outside the `Vehicle` class.

    //   * This protects the data and ensures that it's modified in a controlled manner.

    return 0;
}