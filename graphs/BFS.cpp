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

int main()
{
    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> result = BFS(0 , adj.size() , adj ) ; 

    for ( auto x : result ){
        cout << x << " " ; 
    }

}   