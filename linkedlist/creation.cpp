#include<iostream>
using namespace std ; 

class Node {
    public : 
        int val ; 
        Node * next ; 

        Node( int v ){
            val = v ; 
            next = NULL ; 
        }
};

class LinkedList {
    private :
        Node* head ; 
    
    public :
        LinkedList() {
            head = NULL ; 
        }

        void insertAtHead ( int val ) {
            Node* newNode = new Node(val) ; 
            newNode -> next = head ; 
            head = newNode ; 
        }

        void insertAtTail ( int val ){
            Node * newNode = new Node( val ) ; 
            if ( !head ) {
                head = newNode ; 
                return ;
            }
            Node* temp = head ; 
            while ( temp -> next ) temp = temp -> next ; 
            temp -> next = newNode ; 
        }

        void deleteNode ( int val ){
            if ( !head ) return ; 
            if ( head -> val == val ) {
                Node* temp = head ; 
                head = temp -> next ; 
                delete(temp) ;
                return ; 
            }
            Node* curr = head;
            while (curr->next && curr->next->val != val)
                curr = curr->next;
                if (curr->next) {
                    Node* temp = curr->next;
                    curr->next = temp->next;
                    delete temp;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main()
{

}