#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box() { length = 0; }

    // friend function declaration
    friend void printLength(Box b);

};

// friend function definition
void printLength(Box b) {
    cout << "Length is: " << b.length << endl; // accessing private member
}


int main (){
    cout << " this is the friend function class " << endl ; 
    Box* b = new Box() ; 
    printLength(*b) ; 
}