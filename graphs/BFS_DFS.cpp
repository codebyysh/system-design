#include<iostream>
using namespace std ;

vector<int> BFS (int start , int n , vector<vector<int>> &adj ) {
    vector<int> visited(n , false ) ; 
    queue<int> q ; 
    vector<int> result ; 

    q.push(start) ; 
    visited[start] = true ; 

    while( !q.empty() ){
        int node = q.front() ; 
        q.pop() ; 
        result.push_back(node) ; 

        for ( auto x : adj[node]) {
            if ( !visited[x] ) {
                visited[x] = true ; 
                q.push(x) ; 
            }
        }
    }
    return result ; 
}

void DFS ( int start , vector<vector<int>> & adj , vector<bool> & visited ){
    visited[start] = true ; 
    cout << start << " " ; 
    for ( auto neighbor : adj[start] ) if ( !visited[neighbor] ) DFS( neighbor , adj , visited ) ; 
}

int main()
{
    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> result = BFS(0 , adj.size() , adj ) ; 

    vector<bool> visited ( adj.size() , false ) ; 

    cout << "by DFS traversal " << endl; 
    DFS (0 , adj , visited) ; 


    cout << " by BFS traversal " << endl ; 
    for ( auto x : result ){
        cout << x << " " ; 
    }

}   