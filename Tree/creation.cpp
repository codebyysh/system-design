#include<iostream>
using namespace std ; 

class TreeNode {
   public : 
        int val ; 
        TreeNode* left ;
        TreeNode* right ; 

    public : 
        TreeNode( int val ) {
            this -> val = val ; 
            left = NULL ; 
            right = NULL ; 
        }

};

class BST {
    public : 
        
        TreeNode * insert ( TreeNode* root , int key ){
            if ( !root ) return new TreeNode(key) ;
            if ( root -> val < key ) root -> right =  insert ( root -> right , key ) ; 
            else root -> left = insert ( root -> left , key ) ; 
            return root ; 
        }

        bool search ( TreeNode* root , int key ){
            if ( ! root ) return false ; 
            if ( root -> val == key ) return true ; 
            if ( root -> val < key ) return search ( root -> right , key ) ; 
            else return search ( root ->left , key ) ;  
        }

        void inorder ( TreeNode* root ) {
            if ( !root ) return ; 
            inorder( root -> left ) ; 
            cout << root -> val << " " ; 
            inorder( root -> right ) ; 
        }
};

int main()
{

}