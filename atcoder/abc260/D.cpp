#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> P(N);
    for (auto &x : P) { cin >> x; x--; }
    vector<int> ans(N, -1), prev(N, -1), sz(N, 0);
    set<int> piles;
    for (int i = 0; i < N; i++) {
        int x = P[i];
        auto it = piles.lower_bound(x);
        if (it == piles.end()) {
            piles.insert(x);
            sz[x] = 1;
        } else {
            int y = *it;
            piles.erase(it);
            piles.insert(x);
            sz[x] = sz[y] + 1;
            prev[x] = y;
        }
        if (sz[x] == K) {
            piles.erase(x);
            while (x != -1) {
                ans[x] = i + 1;
                x = prev[x];
            }
        }
    }
    for (auto x : ans) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



