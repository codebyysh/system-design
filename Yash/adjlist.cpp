#include<iostream>
using namespace std ; 

int main()
{
    int n , m ; 
    cout << " enter nodes and edges " << endl ;

    vector<int> adj[n+1] ; 

    for ( int i = 0 ; i < m ; i ++ ){
        int u , v ; 
        cin >> u >> v ; 
        adj[u].push_back(v) ; 
        adj[u].push_back(u) ; 
    }
}