#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

int getLIS(const vector<char>& segment, const map<char, int>& group, 
           int min_group, int max_group) {
    
    if (segment.empty()) {
        return 0;
    }

    int n = segment.size();
    vector<int> dp;
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
        int current_group = group.at(segment[i]);
        
        if (current_group < min_group || current_group > max_group) {
            continue;
        }

        auto it = upper_bound(dp.begin(), dp.end(), current_group);
        
        if (it == dp.end()) {
            dp.push_back(current_group);
        } else {
            *it = current_group;
        }
    }
    return dp.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore(); 

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<char> S(N);
    map<char, int> counts = {{'A', 0}, {'B', 0}, {'C', 0}};
    for (int i = 0; i < N; ++i) {
        ss >> S[i];
        counts[S[i]]++;
    }

    getline(cin, line);
    stringstream ss_fixed(line);
    int pos;
    vector<pair<int, char>> fixed_items;
    while (ss_fixed >> pos) {
        fixed_items.push_back({pos - 1, S[pos - 1]});
    }

    string p = "ABC";
    int min_shifts = numeric_limits<int>::max();
    bool possible = false;

    do {
        map<char, int> group = {{p[0], 1}, {p[1], 2}, {p[2], 3}};
        string target_string = string(counts[p[0]], p[0]) + 
                             string(counts[p[1]], p[1]) + 
                             string(counts[p[2]], p[2]);

        bool valid = true;

        for (const auto& item : fixed_items) {
            if (target_string[item.first] != item.second) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        int last_group = 0;
        for (const auto& item : fixed_items) {
            int current_group = group[item.second];
            if (current_group < last_group) {
                valid = false;
                break;
            }
            last_group = current_group;
        }
        if (!valid) continue;

        possible = true;
        
        int total_lis = 0;
        int last_idx = -1;
        int min_group = 0; 

        for (const auto& item : fixed_items) {
            int current_idx = item.first;
            int current_group = group[item.second];
            
            vector<char> segment;
            for(int i = last_idx + 1; i < current_idx; ++i) {
                segment.push_back(S[i]);
            }

            total_lis += getLIS(segment, group, min_group, current_group);
            total_lis++; 
            
            min_group = current_group;
            last_idx = current_idx;
        }

        vector<char> segment;
        for(int i = last_idx + 1; i < N; ++i) {
            segment.push_back(S[i]);
        }
        total_lis += getLIS(segment, group, min_group, 4);

        min_shifts = min(min_shifts, N - total_lis);

    } while (next_permutation(p.begin(), p.end()));

    if (!possible) {
        cout << "Impossible" << endl;
    } else {
        cout << min_shifts << endl;
    }

    return 0;
}