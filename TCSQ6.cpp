#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm> // For max

using namespace std;

map<string, char> binary_to_digit;
map<char, string> digit_to_binary;
map<string, char> binary_to_op;

string get_3x3_binary(const vector<string>& lines, int offset) {
    string bin = "";
    int start_col = offset * 3;
    for (int i = 0; i < 3; ++i) { // 3 rows
        for (int j = 0; j < 3; ++j) { // 3 cols
            bin += (lines[i][start_col + j] == ' ' ? '0' : '1');
        }
    }
    return bin;
}

string get_binary_for_number(string num_token) {
    string res = "";
    for (char digit : num_token) {
        res += digit_to_binary[digit];
    }
    return res;
}

string pad_binary(string s, int len) {
    if (s.length() >= len) return s;
    return string(len - s.length(), '0') + s;
}

string apply_op(string b1, string b2, char op) {
    int len = max(b1.length(), b2.length());
    b1 = pad_binary(b1, len);
    b2 = pad_binary(b2, len);
    string res = "";
    for (int i = 0; i < len; ++i) {
        if (op == '&') {
            res += (b1[i] == '1' && b2[i] == '1' ? '1' : '0');
        } else if (op == '|') {
            res += (b1[i] == '1' || b2[i] == '1' ? '1' : '0');
        }
    }
    return res;
}

string apply_not(string b) {
    string res = "";
    for (char c : b) {
        res += (c == '0' ? '1' : '0');
    }
    return res;
}

int precedence(char op) {
    if (op == '!') return 3;
    if (op == '|') return 2;
    if (op == '&') return 1;
    return 0;
}

void solve_stack(stack<string>& values, stack<char>& ops) {
    char op = ops.top();
    ops.pop();
    if (op == '!') {
        string b1 = values.top();
        values.pop();
        values.push(apply_not(b1));
    } else {
        string b2 = values.top();
        values.pop();
        string b1 = values.top();
        values.pop();
        values.push(apply_op(b1, b2, op));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> digit_lines(3);
    for (int i = 0; i < 3; ++i) getline(cin, digit_lines[i]);
    for (int i = 0; i < 10; ++i) {
        string bin = get_3x3_binary(digit_lines, i);
        char digit = '0' + i;
        binary_to_digit[bin] = digit;
        digit_to_binary[digit] = bin;
    }

    vector<string> op_lines(3);
    for (int i = 0; i < 3; ++i) getline(cin, op_lines[i]);
    vector<char> op_chars = {'|', '&', '!', '(', ')'};
    for (int i = 0; i < 5; ++i) {
        string bin = get_3x3_binary(op_lines, i);
        binary_to_op[bin] = op_chars[i];
    }

    vector<string> exp_lines(3);
    for (int i = 0; i < 3; ++i) getline(cin, exp_lines[i]);

    vector<string> tokens;
    string current_number = "";
    int num_symbols = exp_lines[0].length() / 3;

    for (int i = 0; i < num_symbols; ++i) {
        string bin = get_3x3_binary(exp_lines, i);
        if (binary_to_digit.count(bin)) {
            current_number += binary_to_digit[bin];
        } else if (binary_to_op.count(bin)) {
            if (!current_number.empty()) {
                tokens.push_back(current_number);
                current_number = "";
            }
            tokens.push_back(string(1, binary_to_op[bin]));
        }
    }
    if (!current_number.empty()) {
        tokens.push_back(current_number);
    }

    stack<string> values;
    stack<char> ops;

    for (const string& token : tokens) {
        if (isdigit(token[0])) {
            values.push(get_binary_for_number(token));
        } else if (token == "(") {
            ops.push('(');
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != '(') {
                solve_stack(values, ops);
            }
            ops.pop(); // Pop '('
        } else {
            char op = token[0];
            while (!ops.empty() && ops.top() != '(' && precedence(ops.top()) >= precedence(op)) {
                solve_stack(values, ops);
            }
            ops.push(op);
        }
    }

    while (!ops.empty()) {
        solve_stack(values, ops);
    }

    string final_binary = values.top();
    for (int i = 0; i < final_binary.length(); i += 9) {
        string chunk = final_binary.substr(i, 9);
        cout << binary_to_digit[chunk];
    }
    cout << endl;

    return 0;
}