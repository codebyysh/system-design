#include <iostream>

#include <vector>
#include <unordered_map>
using namespace std;

// Function to find path from a given start node
unordered_map<int, int> findPath(int start, vector<int>& edge) {
    unordered_map<int, int> dist;
    int step = 0, node = start;
    
    while (node != -1 && dist.find(node) == dist.end()) {
        dist[node] = step++;
        node = edge[node];
    }
    
    return dist;
}

// Function to find the nearest meeting cell
int nearestMeetingCell(int N, vector<int>& edge, int C1, int C2) {
    // Get paths from C1 and C2
    unordered_map<int, int> dist1 = findPath(C1, edge);
    unordered_map<int, int> dist2 = findPath(C2, edge);
    
    int minDist = INT_MAX, meetingCell = -1;

    for (auto [node, d1] : dist1) {
        if (dist2.find(node) != dist2.end()) {  // Node is reachable from both C1 and C2
            int d2 = dist2[node];
            int maxDist = max(d1, d2);

            if (maxDist < minDist) {
                minDist = maxDist;
                meetingCell = node;
            }
        }
    }

    return meetingCell;
}

int main() {
    int N;
    cin >> N;
    vector<int> edge(N);
    cout << " enter the number n " << endl ; 
    for (int i = 0; i < N; i++) {
        cin >> edge[i];
    }
    int C1, C2;
    cout << " enter C1 and C2 " << endl ; 
    cin >> C1 >> C2;

    cout << nearestMeetingCell(N, edge, C1, C2) << endl;
    return 0;
}







typedef struct {
int x;
int y;
} Point;

double distance(Point p1, Point p2) {
return sqrt(pow(p2.x – p1.x, 2) + pow(p2.y – p1.y, 2));
}

int main() {
Point userLocation;
printf(“Enter your current location (x y): “);
scanf(“%d %d”, &userLocation.x, &userLocation.y);

// Define your array of meeting cell locations here
Point meetingCells[] = { /* Add meeting cell locations */ };

int numMeetingCells = sizeof(meetingCells) / sizeof(meetingCells[0]);
double minDistance = -1;
Point nearestCell;

for (int i = 0; i < numMeetingCells; i++) {
double d = distance(userLocation, meetingCells[i]);
if (minDistance == -1 || d < minDistance) {
minDistance = d;
nearestCell = meetingCells[i];
}
}

printf("Nearest meeting cell is at (%d, %d)\n", nearestCell.x, nearestCell.y);
return 0;
}