#include<iostream>
using namespace std ; 

// fibonacci series finding 

int fibonacci ( int n , vector<int> &dp ) {
    if ( n <= 1 ) return n ; 
    if ( dp[n] != -1 ) return dp[n] ; 

    dp[n] = fibonacci(n-1 , dp) + fibonacci(n-2 , dp) ; 
    return dp[n] ; 
}

int fibonacci2 ( int n ) {
    vector<int> dp(n+1) ; 
    dp[0] = 1 ; 
    dp[1] = 1 ; 

    for ( int i = 2 ; i < n ; i ++ ){
        dp[n] = dp[n-1] + dp[n-2] ; 
    }
    return dp[n] ; 
}

int fibonacci3 ( int n ) {
    int prev1 = 0 ; 
    int prev2 = 1 ; 

    for ( int i = 2 ; i < n ; i ++ ){
        int curr = prev1 + prev2 ; 
        prev1 = prev2 ; 
        prev2 = curr ; 
    }
    return prev2 ; 
}


int climbingStairs ( int stairs ) {

}


int maxmagnet ( int x , int y , vector<int> &z ) {
    sort ( z.begin() , z.end() ) ; 
    int maxcount = 0 ; 

    for ( int i = 0 ; i < x ; i ++ ) {
        int count = 1 ; 
        int last = z[i] ; 

        for ( int j = i + 1 ; j < x ; j ++ ) {
            if ( z[j] - last >= y ) {
                count ++ ; 
                last = z[j] ;
            }
        }
        maxcount = max ( maxcount , count ) ; 
    }
    return maxcount ; 
}




int main ()
{

}