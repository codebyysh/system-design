// dynamic programming 
#include<iostream>
using namespace std ; 

int fibonnaci ( int n ) {
    // if ( n == 1 ) return 1 ; 
    // if ( n == 0 ) return 0 ; 

    // return fibonnaci(n-1) + fibonnaci(n-2) ; 

    int a = 0 ; 
    int b = 1 ; 

    for ( int i = 2 ; i < n ; i ++ ){
        int result = a + b ; 
        a = b ; 
        b = result ; 
    }
    return b ; 

}

int main ()
{
    int n ; 
    cout << " fibonacci number " << endl ;
    cin >> n ; 
    cout << fibonnaci(n) ;
}