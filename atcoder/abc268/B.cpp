#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    string S, T; cin >> S >> T;
    for (size_t i = 0; i < S.size(); i++) {
        if (i >= T.size() || S[i] != T[i]) {
            cout << "No\n"; return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}