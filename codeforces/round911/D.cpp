#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int M = 100000;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    vector<vector<int>> cnt(M + 1);
    for (int i = 0; i < n; i++) {
        cnt[arr[i]].emplace_back(i);
    }

    // g[x] = #triples with x being divisor of (a, b)
    // f(x) = #triples with x being gcd of (a, b)
    // f(x) = g[x] - (all g[y] where y is divisor of x)
    vector<LL> g(M + 1, 0);
    for (int x = 1; x <= M; x++) {
        vector<int> idx;
        for (int y = x; y <= M; y += x) {
            idx.insert(idx.end(), cnt[y].begin(), cnt[y].end());
        }
        for (int b_i = 1; b_i < (int)idx.size(); b_i++) {
            int b = idx[b_i];
            LL left = b_i;
            LL right = n - b - 1;
            g[x] += left * right;
        }
    }

    for (int x = M; x > 0; x--) {
        for (int y = x + x; y <= M; y += x) {
            g[x] -= g[y];
        }
    }

    LL ans = 0;
    for (int x = 1; x <= M; x++) {
        ans += g[x] * x;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

