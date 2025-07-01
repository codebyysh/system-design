
#include<iostream>
using namespace std ; 


class DFS {
    public:
        void dfs ( int start , vector<vector<int>> & adj , vector<bool>& visited ){
            visited[start] = true ; 
            cout << start << " " ; 
            for ( auto neighbor : adj[start] ){
                if ( !visited[neighbor] ) dfs(neighbor , adj , visited ) ; 
            }
        }
};




class Solution {
public:

    void dfs ( int i , int j , vector<vector<char>>& grid ){
        int n = grid.size() ; 
        int m = grid[0].size() ; 



        if ( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1' ) return ; 

        grid[i][j] = '2' ;   

        dfs ( i + 1 , j , grid ) ; 
        dfs ( i - 1 , j , grid ) ; 
        dfs ( i , j + 1 , grid ) ; 
        dfs ( i , j - 1 , grid ) ; 

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 

        int count = 0 ; 

        for ( int i = 0 ; i < n ; i ++ ){
            for ( int j = 0 ; j < m ; j ++ ){
                if ( grid[i][j] == '1' ) {
                    dfs ( i , j , grid ) ; 
                    count ++ ; 
                }
            }
        }
        return count ; 
    }
};