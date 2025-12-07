#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double get_initial_area(const vector<Point>& points) {
    long long sum1 = 0;
    long long sum2 = 0;
    int N = points.size();

    for (int i = 0; i < N; ++i) {
        Point p1 = points[i];
        Point p2 = points[(i + 1) % N];
        sum1 += (long long)p1.x * p2.y;
        sum2 += (long long)p1.y * p2.x;
    }

    return 0.5 * abs(sum1 - sum2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    double area0 = get_initial_area(points);

    double perimeter = 0;
    double l_min = numeric_limits<double>::max();

    for (int i = 0; i < N; ++i) {
        Point p1 = points[i];
        Point p2 = points[(i + 1) % N];

        double length = abs(p1.x - p2.x) + abs(p1.y - p2.y);
        
        perimeter += length;
        l_min = min(l_min, length);
    }

    double h_max_val = (l_min - 0.1) / 2.0;

    if (h_max_val <= 0) {
        cout << fixed << setprecision(2) << 0.0 << endl;
        return 0;
    }

    int max_steps = static_cast<int>(floor(h_max_val / 0.1));

    double max_volume = 0.0;

    for (int step = 1; step <= max_steps; ++step) {
        double H = step * 0.1;
        
        double current_volume = area0 * H - perimeter * H * H + 4.0 * H * H * H;
        
        max_volume = max(max_volume, current_volume);
    }

    cout << fixed << setprecision(2) << max_volume << endl;

    return 0;
}