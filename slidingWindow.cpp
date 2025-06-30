// Given an array of integers and a number k, 
//find the maximum sum of a subarray of size k.


#include<iostream>
using namespace std ; 

int max_sum ( vector<int> & vec , int k ) {
    int left = 0 ; 
    int max_sum = INT_MIN ; 
    int window_sum  = 0 ; 
    int right = 0 ; 

    
    while ( right < vec.size() ) {
        window_sum += vec[right] ; 

        if ( right - left + 1 == k ) {
            max_sum = max ( max_sum , window_sum ) ; 
            window_sum -= vec[left] ; 
            left ++ ; 
        }

        right ++ ; 
    }

    return max_sum ; 
}

int main (){
    vector<int> vec = {2,1,5,1,3,2} ;
    int k = 3 ; 

    cout << " the max sum is " << endl ; 

    cout << max_sum(vec , k) << endl ; 

}