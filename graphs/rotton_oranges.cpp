#include<iostream>
using namespace std; 


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[m].size();

        queue<pair<int , int>> q  ; 
        vector<vector<int>> time(n, vector<int>(m, 0));

        int dx[] = {-1, 1, 0, 0}; // up, down
        int dy[] = {0, 0, -1, 1}; // left, right

        for ( int i = 0 ; i < n ; i ++){
            for ( int j = 0 ; j < m ; j ++ ){
                if ( grid[i][j] == 2 ) q.push({i,j}) ; 
            }
        }

        while ( !q.empty() ) {
            auto [x,y] = q.front() ; 
            q.pop() ; 

            for ( int dir = 0 ; dir < 4 ; dir ++ ){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; // rot the fresh orange
                    time[nx][ny] = time[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1; // still fresh? impossible
                maxTime = max(maxTime, time[i][j]);
            }
        }
        return maxTime;
    }
};