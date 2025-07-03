#include<iostream>
using namespace std ; 

class Graph {
    int V ; 
    vector<vector<int>> adj ; 

    public : 
        void BFS (vector<vector<int>>& adj ){
            queue<int> q ; 
            vector<bool> visited ; 

            while ( !q.empty() ) {
                int node = q.front() ; 
                cout << node << " " ; 
                q.pop() ; 

                for ( auto neighbor : adj[node] ) {
                    if ( !visited[neighbor] ) {
                        visited[neighbor] = true ; 
                        q.push(neighbor) ; 
                    }
                }
            }
            cout << endl ; 
        } 


        void DFS ( int start , vector<vector<int>> & adj , vector<bool> visited ){
            visited[start] = true ; 
            cout << start << " " ; 

            for ( auto neighbor : adj[start] ) {
                if ( !visited[neighbor] ) {
                    DFS( neighbor , adj , visited ) ; 
                }
            }
        }
};

int main()
{

}