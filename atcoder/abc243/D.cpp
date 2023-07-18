#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

string simplify(string s) {
    string ans;
    for (auto ch : s) {
        if (ch != 'U') ans.push_back(ch);
        else {
            if (ans.empty() || ans.back() == 'U') ans.push_back(ch);
            else ans.pop_back();
        }
    }
    return ans;
}

void solve() {
    LL n, x; cin >> n >> x;
    string op; cin >> op;
    op = simplify(op);
    for (auto dir : op) {
        if (dir == 'U') x /= 2;
        else if (dir == 'L') x = x * 2;
        else x = x * 2 + 1;
    }
    cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



