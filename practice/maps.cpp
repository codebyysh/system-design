#include<iostream>
using namespace std ; 

#include<unordered_set> 

int freq_count ( vector<int> & arr , int target ){
    unordered_map<int , int > mp ; 
    for ( int it : arr ){
        mp[it] ++ ; 
    }
    return mp[target] ; 
}

vector<int> unique ( vector<int> &arr ){
    unordered_set <int> set ; 

    for ( int it : arr ){
        set.insert(it) ; 
    }
    vector<int> result ( set.begin() , set.end() ) ; 
    return result ; 
}

int main ()
{
    vector<int> arr = { 1,2,3,3,2,1,2,3,4,5,6,3,2,1,2,3,4 , 1 } ; 
    // int target ; 
    // cout << " give me the tatget " << endl ; 
    // cin >> target ; 
    // cout << "the frequency of the element is " << freq_count(arr , target )<< endl ;

    vector<int> distinct = unique(arr) ; 
    for ( int x : distinct ) cout << x << " " ; 
    cout << endl; 

}