#include<iostream>
using namespace std ; 

class Queue {
    private :
        vector<int> arr ; 
        int frontIdx = 0 ; 
    public:
        void enqueue(int val ){
            arr.push_back(val) ; 
        }

        void dequeue(){
            if ( frontIdx < arr.size() ){
                frontIdx ++ ;
            }
        }

        int front (){
            return arr[frontIdx] ? frontIdx < arr.size() : -1 ; 
        }

        bool isEmpty() {
            return arr.empty() ? frontIdx >= arr.size() : -1  ; 
        }

};

int main()
{

}