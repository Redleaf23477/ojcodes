#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(LL S, vector<tuple<LL,LL,LL>> const &arr, int N) {
    vector<bool> vis(N, false), span(N, false);
    function<void(int, bool)> dfs = [&](int u, bool rev) {
        vis[u] = true, span[u] = true;
        auto [ux, uy, up] = arr[u];
        for (int v = 0; v < N; v++) {
            if (vis[v]) continue;
            auto [vx, vy, vp] = arr[v];
            LL dist = abs(vx - ux) + abs(vy - uy);
            LL w = (rev? (dist + vp - 1) / vp : (dist + up - 1) / up);
            if (w <= S) dfs(v, rev);
        }
    };

    for (int start = 0; start < N; start++) {
        span.assign(N, false);
        vis.assign(N, false);
        dfs(start, false);
        vis.assign(N, false);
        dfs(start, true);
        bool ok = true;
        for (auto x : span) {
            if (!x) ok = false;
        }
        if (ok) return true;
    }
    return false;
}

void solve() {
    int N; cin >> N;
    vector<tuple<LL,LL,LL>> arr(N);
    for (auto &[x, y, p] : arr) cin >> x >> y >> p;
    LL low = 1, high = 4'000'000'000, mid, ans = high;
    while (low <= high) {
        mid = (low + high) / 2;
        if (good(mid, arr, N)) {
            ans = mid, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



