#include<iostream>
using namespace std ; 

void bfs ( int V , vector<int> adj[] ) {
    vector<bool> visited(V , false ) ; 
    queue<int> q ; 

    for ( int i = 0 ; i < V ; i ++ ){
        if ( !visited[i] ) {
            q.push(i) ; 
            visited[i] = true ; 

            while ( !q.empty()) {
                int node = q.front() ; 
                q.pop() ; 
                cout << node << " " ; 

                for ( int neighbor : adj[node] ) {
                    if ( !visited[neighbor] ) {
                        q.push(neighbor) ; 
                        visited[neighbor] = true ; 
                    }
                }
            }
        }
    }
}