#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Rect {
    int r1, c1, r2, c2;
};

int N, M;
char grid[30][30];
bool visited[30][30];
vector<Rect> clues[35];
string target;
int min_faults;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int calculate_faults(int r, int c, int time) {
    int faults = 0;
    for (const auto& rect : clues[time]) {
        if (r >= rect.r1 && r <= rect.r2 && c >= rect.c1 && c <= rect.c2) {
            faults++;
        }
    }
    return faults;
}

void dfs(int r, int c, int idx, int current_faults) {
    if (current_faults >= min_faults) return;

    if (idx == (int)target.length() - 1) {
        min_faults = min(min_faults, current_faults);
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]) {
            if (grid[nr][nc] == target[idx + 1]) {
                int next_time = idx + 2;
                int new_faults = current_faults + calculate_faults(nr, nc, next_time);
                dfs(nr, nc, idx + 1, new_faults);
            }
        }
    }

    visited[r][c] = false;
}

void solve() {
    if (!(cin >> N >> M)) return;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    int K;
    cin >> K;

    for (int i = 0; i <= 30; ++i) clues[i].clear();

    for (int i = 0; i < K; ++i) {
        int t, r1, c1, r2, c2;
        cin >> t >> r1 >> c1 >> r2 >> c2;
        if (t <= 30) {
            clues[t].push_back({r1 - 1, c1 - 1, r2 - 1, c2 - 1});
        }
    }

    cin >> target;
    min_faults = 2e9;

    int len = (int)target.length();
    if (len == 0) {
        cout << "All clues are correct" << endl;
        return;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == target[0]) {
                int init_faults = calculate_faults(i, j, 1);
                dfs(i, j, 0, init_faults);
            }
        }
    }

    if (min_faults == 2e9) {
        cout << "Impossible" << endl;
    } else if (min_faults == 0) {
        cout << "All clues are correct" << endl;
    } else {
        cout << min_faults << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}