#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    stack<string> stk;
    while (T--) {
        string cmd, name; cin >> cmd;
        if (cmd[0] == 'S') {
            cin >> name;
            stk.emplace(name);
        } else if (cmd[0] == 'T') {
            if (stk.empty()) {
                cout << "Not in a dream\n";
            } else {
                cout << stk.top() << "\n";
            }
        } else {
            if (!stk.empty()) stk.pop();
        }
    }
}

