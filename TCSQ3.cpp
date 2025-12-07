#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

map<vector<string>, char> display_to_digit;
map<int, int> toggle_map;

// Big Integer (String) Subtraction
string string_subtract(string s1, string s2) {
    string res = "";
    int n1 = s1.length(), n2 = s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub = ((s1[i] - '0') - (s2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        res.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++) {
        int sub = ((s1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        res.push_back(sub + '0');
    }
    reverse(res.begin(), res.end());
    // Remove leading zeros
    size_t first_digit = res.find_first_not_of('0');
    if (string::npos == first_digit) return "0";
    return res.substr(first_digit);
}

void initialize_maps() {
    display_to_digit[{" _ ", "| |", "|_|"}] = '0';
    display_to_digit[{" ", " |", " |"}] = '1';
    display_to_digit[{" _ ", " _|", "|_ "}] = '2';
    display_to_digit[{" _ ", " _|", " _|"}] = '3';
    display_to_digit[{" ", "|_|", " |"}] = '4';
    display_to_digit[{" _ ", "|_ ", " _|"}] = '5';
    display_to_digit[{" _ ", "|_ ", "|_|"}] = '6';
    display_to_digit[{" _ ", " |", " |"}] = '7';
    display_to_digit[{" _ ", "|_|", "|_|"}] = '8';
    display_to_digit[{" _ ", "|_|", " _|"}] = '9';

    // 1-Segment Flip Map (Rule-Compliant)
    for(int i=0; i<=9; ++i) toggle_map[i] = -1;
    toggle_map[0] = 8;
    toggle_map[1] = 7;
    toggle_map[3] = 9;
    toggle_map[5] = 6;
    toggle_map[6] = 5;
    toggle_map[7] = 1;
    toggle_map[8] = 0;
    toggle_map[9] = 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initialize_maps();
    string line1, line2, line3;
    getline(cin, line1);
    getline(cin, line2);
    getline(cin, line3);
    int K;
    cin >> K;

    string original_num_s = "";
    int n = line1.length();
    for (int i = 0; i < n; i += 3) {
        vector<string> chunk = {
            line1.substr(i, 3),
            line2.substr(i, 3),
            line3.substr(i, 3)
        };
        original_num_s += display_to_digit[chunk];
    }

    string modified_num_s = original_num_s;
    int num_digits = original_num_s.length();
    vector<bool> toggled(num_digits, false);

    for (int k = 0; k < K; ++k) {
        int best_index = -1;
        int min_replacement = 10;
        for (int i = 0; i < num_digits; ++i) {
            if (toggled[i]) continue;
            int current_digit = modified_num_s[i] - '0';
            int target_digit = toggle_map[current_digit];
            if (target_digit != -1) {
                if (target_digit < min_replacement) {
                    min_replacement = target_digit;
                    best_index = i;
                }
            }
        }
        if (best_index != -1) {
            modified_num_s[best_index] = (char)(min_replacement + '0');
            toggled[best_index] = true;
        } else {
            break;
        }
    }

    string next_anagram_s = modified_num_s;
    next_permutation(next_anagram_s.begin(), next_anagram_s.end());

    // Use string comparison and subtraction
    string s1 = original_num_s;
    string s2 = next_anagram_s;
    if (s1.length() < s2.length() || (s1.length() == s2.length() && s1 < s2)) {
        swap(s1, s2);
    }
    cout << string_subtract(s1, s2) << endl;

    return 0;
}