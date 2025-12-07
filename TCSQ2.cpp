#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string temp;
    cin >> temp; 
    vector<string> shuffled(N), original(N);

    cin.ignore(); // consume leftover newline
    for (int i = 0; i < N; i++) {
        getline(cin, shuffled[i]);
    }

    cin >> temp;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, original[i]);
    }

    int maxMatch = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int len = 0;
            while (i + len < N && j + len < N && shuffled[i + len] == original[j + len]) {
                len++;
            }
            if (len > maxMatch) maxMatch = len;
        }
    }

    cout << (N - maxMatch) << "\n";
    return 0;
}