#include<iostream>
using namespace std ; 

void topo ( int start , vector<vector<int>> & adj , vector<bool> & visited , vector<int>& result  ){

    visited[start] = true ;  

    for ( auto neighbor : adj[start] ) {
        if ( !visited[neighbor] ) {
            topo( neighbor , adj , visited , result ) ; 
        }
    }

    result.push_back(start) ; 
    
}


int main ()
{
    vector<vector<int>> adj = {
    {1, 2},    // 0 → 1, 2
    {3},       // 1 → 3
    {3},       // 2 → 3
    {},        // 3 → nothing
    {5},       // 4 → 5
    {}         // 5 → nothing
};

    

    vector<int> result ; 
    vector<bool> visited ( adj.size() , false ) ; 
    int start = 0;

    for ( int i = 0 ; i < adj.size() ; i ++ ){
        if ( !visited[i] ) topo(start , adj , visited , result ) ; 
    }
    
    for ( auto x : result ) cout << x << " " ; 

}