#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
int grid[55][55];
int targetID;
map<int, vector<pair<int, int>>> pieceCells;
map<int, int> totalSupports;

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int calculateSupport(int p) {
    int supports = 0;
    bool onFloor = false;
    for (auto cell : pieceCells[p]) {
        int r = cell.first;
        int c = cell.second;
        int belowR = r + 1;
        
        if (belowR == N) {
            onFloor = true;
        } else if (grid[belowR][c] != 0 && grid[belowR][c] != p) {
            supports++;
        }
    }
    return onFloor ? 2e9 : supports;
}

int simulateDropDist(int u, const set<int>& removed) {
    int minDrop = N; 
    
    map<int, int> bottomRowInCol;
    for(auto cell : pieceCells[u]) {
        int r = cell.first;
        int c = cell.second;
        bottomRowInCol[c] = max(bottomRowInCol[c], r);
    }

    for (auto entry : bottomRowInCol) {
        int c = entry.first;
        int r_start = entry.second;
        int dist = 0;
        
        for (int r = r_start + 1; r < N; ++r) {
            int obstacle = grid[r][c];
            if (obstacle != 0 && removed.find(obstacle) == removed.end()) {
                break;
            }
            dist++;
        }
        minDrop = min(minDrop, dist);
    }
    return minDrop;
}

long long solveDirection(int dr, int dc) {
    set<int> removed;
    queue<int> q;
    long long currentCost = 0;
    map<int, int> currentLostSupport;

    q.push(targetID);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto cell : pieceCells[u]) {
            int r = cell.first;
            int c = cell.second;
            int nr = r + dr;
            int nc = c + dc;

            if (isValid(nr, nc)) {
                int neighbor = grid[nr][nc];
                if (neighbor != 0 && neighbor != u && removed.find(neighbor) == removed.end()) {
                    if (neighbor == targetID) continue;
                    
                    removed.insert(neighbor);
                    currentCost += neighbor;
                    q.push(neighbor);
                }
            }
        }

        if (u == targetID) continue; 

        for (auto const& entry : pieceCells) {
            int pid = entry.first;
            const vector<pair<int, int>>& cells = entry.second;

            if (removed.find(pid) != removed.end() || pid == targetID) continue;

            int lost = 0;
            for (auto c : cells) {
                int belowR = c.first + 1;
                int col = c.second;
                if (belowR < N && grid[belowR][col] == u) {
                    lost++;
                }
            }

            if (lost > 0) {
                currentLostSupport[pid] += lost;
                
                if (currentLostSupport[pid] >= totalSupports[pid]) {
                    int dropDist = simulateDropDist(pid, removed);
                    bool intersectsTunnel = false;
                    
                    for (auto pCell : cells) {
                        int fallR = pCell.first + dropDist;
                        int fallC = pCell.second;
                        
                        for (auto tCell : pieceCells[targetID]) {
                            int tr = tCell.first;
                            int tc = tCell.second;
                            
                            if (dr == 1 && dc == 0) {
                                if (fallC == tc && fallR > tr) intersectsTunnel = true;
                            } else if (dr == -1 && dc == 0) {
                                if (fallC == tc && fallR < tr) intersectsTunnel = true;
                            } else if (dr == 0 && dc == 1) {
                                if (fallR == tr && fallC > tc) intersectsTunnel = true;
                            } else if (dr == 0 && dc == -1) {
                                if (fallR == tr && fallC < tc) intersectsTunnel = true;
                            }
                        }
                    }
                    
                    if (intersectsTunnel) {
                        removed.insert(pid);
                        currentCost += pid;
                        q.push(pid);
                    }
                }
            }
        }
    }
    return currentCost;
}

void solve() {
    if (!(cin >> N >> M)) return;

    pieceCells.clear();
    totalSupports.clear();
    
    for(int i=0; i<55; ++i) for(int j=0; j<55; ++j) grid[i][j] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                pieceCells[grid[i][j]].push_back({i, j});
            }
        }
    }
    cin >> targetID;

    for (auto const& entry : pieceCells) {
        int id = entry.first;
        totalSupports[id] = calculateSupport(id);
    }

    struct Result {
        long long cost;
        string name;
    };
    
    vector<Result> results;
    results.push_back({solveDirection(1, 0), "down"});
    results.push_back({solveDirection(-1, 0), "up"});
    results.push_back({solveDirection(0, -1), "left"});
    results.push_back({solveDirection(0, 1), "right"});

    long long bestCost = results[0].cost;
    string bestSide = results[0].name;

    for (size_t i = 1; i < results.size(); ++i) {
        if (results[i].cost < bestCost) {
            bestCost = results[i].cost;
            bestSide = results[i].name;
        }
    }

    cout << bestCost << " via " << bestSide << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}