#include <iostream>

using namespace std; // Using namespace std

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x ; 
        this -> y = y ; 
    }

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    void print() {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    p3.print();
    return 0;
}