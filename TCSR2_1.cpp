#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct State {
    int r; // Ring level
    int i; // Index in the ring
};

int solve() {
    int N;
    // Check if input exists
    if (!(cin >> N)) return 0;

    vector<string> rings(N);
    for (int i = 0; i < N; ++i) {
        cin >> rings[i];
    }

    // Initialize visited/distance array
    vector<vector<int>> dist(N);
    for (int r = 0; r < N; ++r) {
        dist[r].assign(rings[r].length(), -1);
    }

    queue<State> q;

    // Start from the Outermost Ring (N-1)
    int start_ring = N - 1;
    
    // FIX: Cast .length() to int to avoid signed/unsigned warning
    int start_len = (int)rings[start_ring].length();
    
    for (int i = 0; i < start_len; ++i) {
        if (rings[start_ring][i] == '0') {
            q.push({start_ring, i});
            dist[start_ring][i] = 1;
        }
    }

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int r = current.r;
        int i = current.i;
        int d = dist[r][i];

        // Target Reached (Any room in innermost ring)
        if (r == 0) {
            return d;
        }

        // FIX: Cast .length() to int here as well
        int size = (int)rings[r].length();

        // 1. Move Left (Circular)
        // Adding 'size' before modulo ensures the result is positive
        int left = (i - 1 + size) % size;
        if (rings[r][left] == '0' && dist[r][left] == -1) {
            dist[r][left] = d + 1;
            q.push({r, left});
        }

        // 2. Move Right (Circular)
        int right = (i + 1) % size;
        if (rings[r][right] == '0' && dist[r][right] == -1) {
            dist[r][right] = d + 1;
            q.push({r, right});
        }

        // 3. Move Inwards (Towards Center: Ring r-1)
        if (r > 0) {
            int inner_r = r - 1;
            int inner_i = i / 2; // Integer division maps outer to inner correctly
            if (rings[inner_r][inner_i] == '0' && dist[inner_r][inner_i] == -1) {
                dist[inner_r][inner_i] = d + 1;
                q.push({inner_r, inner_i});
            }
        }

        // 4. Move Outwards (Away from Center: Ring r+1)
        if (r < N - 1) {
            int outer_r = r + 1;
            int outer_i_1 = 2 * i;
            int outer_i_2 = 2 * i + 1;

            // Check first outer connection
            if (rings[outer_r][outer_i_1] == '0' && dist[outer_r][outer_i_1] == -1) {
                dist[outer_r][outer_i_1] = d + 1;
                q.push({outer_r, outer_i_1});
            }
            // Check second outer connection
            if (rings[outer_r][outer_i_2] == '0' && dist[outer_r][outer_i_2] == -1) {
                dist[outer_r][outer_i_2] = d + 1;
                q.push({outer_r, outer_i_2});
            }
        }
    }

    return -1;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << solve() << endl;
    
    return 0;
}