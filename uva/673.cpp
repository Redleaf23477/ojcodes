#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool solve() {
    string str; getline(cin, str);
    stack<char> stk;
    for (auto c : str) {
        if (c == '(' || c == '[') {
            stk.emplace(c); 
        } else if (stk.empty()) {
            return false; 
        } else if (c == ')') {
            if (stk.top() == '(') stk.pop();
            else return false;
        } else if (c == ']') {
            if (stk.top() == '[') stk.pop();
            else return false;
        } else {
            assert(false);
        }
    }
    return stk.empty();
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T >> ws;
    while (T--) {
        if (solve()) cout << "Yes\n";
        else cout << "No\n";
    }
}

