#include<iostream>
using namespace std ; 

vector<int> arr ;

class Stack {
    public:

        void push ( int val ){
            arr.push_back(val) ; 
        }

        void pop () {
            if ( !arr.empty() ) 
                arr.pop_back() ; 
        }

        int top () {
            return arr.empty() ? -1 : arr.back() ; 
        }

        bool isEmpty() {
            return arr.empty() ; 
        }
};

int main() {

}