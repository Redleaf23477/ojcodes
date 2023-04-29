#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(vector<pair<int,int>> &exchange) {
    if (exchange.size() == 2) {
        auto [a, b] = exchange[0];
        auto [c, d] = exchange[1];
        if (a == d && b == c) return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<pair<int,int>> exchange;
    for (int start = 0; start < k; start++) {
        for (int i = start; i < n; i += k) {
            int group = (arr[i] - 1) % k;
            if (group != start) exchange.emplace_back(start, group);
        }
    }
    if (exchange.size() == 0) {
        cout << 0 << "\n";
    } else if (good(exchange)) {
        cout << 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



