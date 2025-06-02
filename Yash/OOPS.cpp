#include <iostream>
using namespace std;

// 1️⃣ Class & Object + Encapsulation + Abstraction
class Person {
private:
    string name;
    int age;

public:
    // Constructor using this-> (no initializer list)
    Person(string n, int a) {
        this->name = n;
        this->age = a;
    }

    // Getter method (Abstraction)
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Setter (Encapsulation)
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    // Virtual function (for Runtime Polymorphism)
    virtual void showRole() {
        cout << "I am a Person." << endl;
    }

    // Destructor
    ~Person() {
        cout << name << " is deleted.\n";
    }
};

// 2️⃣ Inheritance (Single)
class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a) {
        this->empID = id;
    }

    void showRole() override {
        cout << "I am an Employee. ID: " << empID << endl;
    }
};

// 3️⃣ Inheritance (Multilevel)
class Manager : public Employee {
public:
    Manager(string n, int a, int id) : Employee(n, a, id) {}

    void showRole() override {
        cout << "I am a Manager. ID: " << empID << endl;
    }
};

// 4️⃣ Inheritance (Hierarchical)
class Developer : public Employee {
public:
    Developer(string n, int a, int id) : Employee(n, a, id) {}

    void showRole() override {
        cout << "I am a Developer. ID: " << empID << endl;
    }
};

// 5️⃣ Operator Overloading
class Point {
    int x, y;

public:
    // Constructor without initializer list
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Overload + operator
    Point operator + (const Point& p) {
        return Point(x + p.x, y + p.y);
    }

    void print() {
        cout << "Point(" << x << ", " << y << ")\n";
    }
};

// 6️⃣ Friend Function
class Box {
private:
    int length;

public:
    Box() {
        length = 0;
    }

    void setLength(int l) {
        length = l;
    }

    friend void printLength(Box b);
};

void printLength(Box b) {
    cout << "Length is: " << b.length << endl;
}

// 🔚 Main function
int main() {
    cout << "=== Encapsulation, Abstraction, Constructor, Destructor ===\n";
    Person p1("Yash", 20);
    p1.display();
    p1.setName("Yashu");
    cout << "Updated Name: " << p1.getName() << "\n";

    cout << "\n=== Inheritance & Polymorphism ===\n";
    Manager m("Ankit", 30, 101);
    Developer d("Meena", 25, 102);

    Person* ptr;
    ptr = &m;
    ptr->showRole(); // Runtime Polymorphism

    ptr = &d;
    ptr->showRole();

    cout << "\n=== Operator Overloading ===\n";
    Point a(2, 3), b(4, 5);
    Point c = a + b; // Operator overloading
    c.print();

    cout << "\n=== Friend Function ===\n";
    Box box;
    box.setLength(15);
    printLength(box); // Friend function accessing private member

    return 0;
}


