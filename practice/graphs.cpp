#include<iostream>
using namespace std ; 

vector<int> DFS ( vector<vector<int> > adjlist , int start ){
    int n = adjlist.size() ; 
    vector<int> result ; 
    vector<int> visited (n,0) ; 
    visited[start] = 1 ; 

    queue<int> q ; 
    q.push(start) ;

    while ( !q.empty() ) {
        int node = q.front() ; 
        q.pop() ; 
        result.push_back(node) ; 

        for ( auto it : adjlist[node] ){
            if( !visited[it] ){
                visited[it] =1 ; 
                q.push(it) ; 
            }
        }
    }
    return result ; 

}

vector<int> DFS ( vector<vector<int> > adjlist , vector<int> visited , int start  , vector<int> result ){
    visited[start] = 1  ;
    result.push_back(start) ; 

    for ( auto it : adjlist[start] ) {
        if ( !visited[it] ) DFS( adjlist , visited , it , result ) ;
    }

    return result ; 
}


int main (){

}