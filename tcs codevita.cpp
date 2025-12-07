#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct State {
    int r, c;           
    int orientation;    // 0: horizontal, 1: vertical
    int step;          
    State(int _r, int _c, int _o, int _s) : r(_r), c(_c), orientation(_o), step(_s) {}
};

const int dr[] = {-1, 1, 0, 0}; 
const int dc[] = {0, 0, -1, 1}; 

bool isValid(char cell) {
    return cell == '0' || cell == 'S' || cell == 's';
}

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<char>> grid(M, vector<char>(N));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];

    // Find start (s) and end (S) positions separately
    vector<pair<int,int>> startPos, endPos;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 's') startPos.push_back({i, j});
            if(grid[i][j] == 'S') endPos.push_back({i, j});
        }
    }

    if(startPos.size() != 2 || endPos.size() != 2) {
        cout << "Invalid input: Need exactly 2 start and 2 end positions\n";
        return 1;
    }

    // Sort positions to ensure consistent ordering
    sort(startPos.begin(), startPos.end());
    sort(endPos.begin(), endPos.end());

    // Determine initial orientation and position
    int startOrientation = (startPos[0].first == startPos[1].first) ? 0 : 1;
    int endOrientation = (endPos[0].first == endPos[1].first) ? 0 : 1;
    
    State start(startPos[0].first, startPos[0].second, startOrientation, 0);
    State goal(endPos[0].first, endPos[0].second, endOrientation, 0);

    vector<vector<vector<bool>>> visited(M, 
        vector<vector<bool>>(N, vector<bool>(2, false)));
    
    queue<State> q;
    q.push(start);
    visited[start.r][start.c][start.orientation] = true;

    while(!q.empty()) {
        State curr = q.front();
        q.pop();

        if(curr.r == goal.r && curr.c == goal.c && 
           curr.orientation == goal.orientation) {
            cout << curr.step << endl;
            return 0;
        }

        // Try movements
        for(int d = 0; d < 4; d++) {
            int nr = curr.r + dr[d], nc = curr.c + dc[d];
            int nr2 = nr + (curr.orientation == 1);
            int nc2 = nc + (curr.orientation == 0);
            
            if(nr >= 0 && nr2 < M && nc >= 0 && nc2 < N && 
               isValid(grid[nr][nc]) && isValid(grid[nr2][nc2]) && 
               !visited[nr][nc][curr.orientation]) {
                visited[nr][nc][curr.orientation] = true;
                q.push(State(nr, nc, curr.orientation, curr.step + 1));
            }
        }

        // Try rotations
        if(curr.orientation == 0) {
            for(int k = -1; k <= 0; k++) {
                if(curr.r + k >= 0 && curr.r + k + 1 < M && 
                   curr.c >= 0 && curr.c + 1 < N) {
                    bool canRotate = true;
                    for(int i = 0; i < 2; i++)
                        for(int j = 0; j < 2; j++)
                            if(!isValid(grid[curr.r + k + i][curr.c + j]))
                                canRotate = false;
                    
                    if(canRotate && !visited[curr.r + k][curr.c][1]) {
                        visited[curr.r + k][curr.c][1] = true;
                        q.push(State(curr.r + k, curr.c, 1, curr.step + 1));
                    }
                }
            }
        } else {
            for(int k = -1; k <= 0; k++) {
                if(curr.r >= 0 && curr.r + 1 < M && 
                   curr.c + k >= 0 && curr.c + k + 1 < N) {
                    bool canRotate = true;
                    for(int i = 0; i < 2; i++)
                        for(int j = 0; j < 2; j++)
                            if(!isValid(grid[curr.r + i][curr.c + k + j]))
                                canRotate = false;
                    
                    if(canRotate && !visited[curr.r][curr.c + k][0]) {
                        visited[curr.r][curr.c + k][0] = true;
                        q.push(State(curr.r, curr.c + k, 0, curr.step + 1));
                    }
                }
            }
        }
    }
    
    cout << "-1" << endl;
    return 0;
}