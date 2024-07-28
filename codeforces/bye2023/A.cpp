#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> b(n);
    LL mul = 1;
    for (auto &x : b) {
        cin >> x;
        mul *= x;
    }
    if (2023 % mul == 0) {
        cout << "YES\n";
        cout << 2023 / mul;
        for (int i = 1; i < k; i++) cout << " " << 1;
        cout << "\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

