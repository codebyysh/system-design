#include<iostream>
using namespace std ; 

vector<int> BFS ( vector<vector<int>> adjlist ) {
    int n = adjlist.size() ; 

    vector<int> BFS ; 

    vector<int> visited ( n , 0 ) ;
    visited[0] = 1 ; 

    queue<int> q ; 
    q.push(0) ; 

    while ( !q.empty() ){
        int node = q.front() ; 
        q.pop() ;
        BFS.push_back(node) ; 

        for ( auto it : adjlist[node] ){
            if ( !visited[it] ) {
                visited[it] = 1 ; 
                q.push(it) ; 
            }
        }

    }

    return BFS ; 
}

vector<int> DFS ( int node , vector<vector<int>> adjlist , vector<int> visited , vector<int> & result  ){
    visited[node] = 1 ; 
    result.push_back(node) ; 

    for ( auto it : adjlist[node] ) {
        if ( !visited[it] ) DFS ( it , adjlist , visited , result ) ; 
    }

    return result ; 
}


bool detectCycle ( vector<vector<int>> adjlist , int start , vector<int>visited , int parent ){
    visited[start] = 1 ; 

    for ( auto it : adjlist[start] ) {
        if ( it == parent ) continue ; 
        if ( visited[it] ) return true ;
        else if (DFS( it , adjlist , visited , result )) return true ; 
    }

    return false ; 
}


int main (){
    int n , m ; 
    cout << " enter the number of nodes and edges in a graph " << endl ; 
    cin >> n >> m ; 

    int adj[n+1][m+1] ; 

    for ( int i = 0 ; i < m ; i ++ ){
        int u , v ; 
        cin >> u >> v ; 
        adj[u][v] = 1 ; 
        adj[v][u] = 1 ; 
    }
    return 0 ; 
} 