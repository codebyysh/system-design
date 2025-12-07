#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct Line {
    Point p1, p2;
    Line(int x1, int y1, int x2, int y2) {
        Point pt1 = {x1, y1};
        Point pt2 = {x2, y2};
        if (pt2 < pt1) swap(pt1, pt2);
        p1 = pt1;
        p2 = pt2;
    }
    bool operator<(const Line& other) const {
        if (!(p1 == other.p1)) return p1 < other.p1;
        return p2 < other.p2;
    }
};

int face_rules[6][4] = {
    {1, 2, 3, 4},
    {5, 2, 0, 4},
    {5, 3, 0, 1},
    {5, 4, 0, 2},
    {5, 1, 0, 3},
    {3, 2, 1, 4}
};

map<Point, vector<Point>> adj;
vector<Point> squares;

bool check_fold(Point start_node) {
    map<Point, int> faces;
    queue<Point> q;

    q.push(start_node);
    faces[start_node] = 0; 

    int processed_count = 0;

    while (!q.empty()) {
        Point u_sq = q.front();
        q.pop();
        processed_count++;
        int u_face = faces[u_sq];

        for (const auto& v_sq : adj[u_sq]) {
            int direction = -1;
            if (v_sq.y == u_sq.y + 1) direction = 0;
            else if (v_sq.x == u_sq.x + 1) direction = 1;
            else if (v_sq.y == u_sq.y - 1) direction = 2;
            else if (v_sq.x == u_sq.x - 1) direction = 3;

            int v_face = face_rules[u_face][direction];

            if (faces.count(v_sq)) {
                if (faces[v_sq] != v_face) {
                    return false;
                }
            } else {
                faces[v_sq] = v_face;
                q.push(v_sq);
            }
        }
    }
    return faces.size() == 6;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    set<Line> lines;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.insert(Line(x1, y1, x2, y2));
    }

    for (int x = 0; x < 25; ++x) {
        for (int y = 0; y < 25; ++y) {
            Line l1(x, y, x + 1, y);
            Line l2(x + 1, y, x + 1, y + 1);
            Line l3(x, y + 1, x + 1, y + 1);
            Line l4(x, y, x, y + 1);

            if (lines.count(l1) && lines.count(l2) && lines.count(l3) && lines.count(l4)) {
                squares.push_back({x, y});
            }
        }
    }

    if (squares.size() != 6) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            Point p1 = squares[i];
            Point p2 = squares[j];
            int dx = abs(p1.x - p2.x);
            int dy = abs(p1.y - p2.y);
            if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1)) {
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
            }
        }
    }

    set<Point> visited;
    queue<Point> q_conn;
    q_conn.push(squares[0]);
    visited.insert(squares[0]);
    while(!q_conn.empty()) {
        Point u = q_conn.front();
        q_conn.pop();
        for(const auto& v : adj[u]) {
            if(visited.find(v) == visited.end()) {
                visited.insert(v);
                q_conn.push(v);
            }
        }
    }

    if (visited.size() != 6) {
        cout << 0 << endl;
        return 0;
    }
    
    bool possible = false;
    for (int i = 0; i < 6; ++i) {
        if (check_fold(squares[i])) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}