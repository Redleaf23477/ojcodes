#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();

    map<char,int> preced;
    preced['('] = 0;
    preced['+'] = preced['-'] = 1;
    preced['*'] = preced['/'] = 2;


    int T; cin >> T >> ws;
    string buff;

    stack<char> op;
    while (getline(cin, buff)) {
        if (buff.size() == 0) {
            while (!op.empty()) {
                cout << op.top();
                op.pop();
            }
            cout << "\n\n";
        } else {
            char c = buff[0];
            int pc = preced[c];
            if (isdigit(c)) {
                cout << c;
            } else if (c == '(') {
                op.emplace(c);
            } else if (c == ')') {
                while (op.top() != '(') {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            } else if (op.empty() || pc > preced[op.top()]) {
                op.emplace(c);
            } else {
                while (!op.empty() && pc <= preced[op.top()]) {
                    cout << op.top(); op.pop();
                }
                op.emplace(c);
            }
        }
    }
    while (!op.empty()) {
        cout << op.top();
        op.pop();
    }
    cout << "\n";
}

