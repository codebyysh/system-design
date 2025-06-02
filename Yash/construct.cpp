#include<iostream>
using namespace std ; 

class Teacher {
    private :
        double salary ; 
    public : 
        string name ; 
        int prof_id ; 

        // // my parameterised constructor 
        Teacher (string n , int id , double x ){
            this -> name = n ; 
            this -> prof_id = id ; 
            this -> salary = x ; 
        }

        void setinfo ( string n , int id , double x ){
            this -> name = n ; 
            this -> prof_id = id ; 
            this -> salary = x ;
        }

        void getinfo ( ) {
            cout << " the name of the professor is " << name << endl ; 
            cout << " the id for the teacher is  " << prof_id << endl ; 
            cout << " the salary of this person is " << salary << endl ;
        }

        // copy constructor 
        Teacher( Teacher &orgobj ) {
            cout << " i m a copy constructor " << endl ; 
            this -> name = orgobj.name ; 
            this -> prof_id = orgobj.prof_id ; 
        }
};


int main () 
{
    Teacher t1("Yash" , 849 , 4000.90) ;
    t1.getinfo() ;  

    cout << endl ; 

    Teacher t2(t1) ; 
    t2.getinfo() ; 

    
}