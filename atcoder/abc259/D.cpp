#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr double eps = 1e-6;

void solve() {
    int N; cin >> N;
    LL sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    vector<tuple<LL,LL,LL>> circle(N);
    for (auto &[x, y, r] : circle) cin >> x >> y >> r;

    auto point_on_circle = [](LL x, LL y, tuple<LL,LL,LL> cir) {
        auto [cx, cy, cr] = cir;
        LL dx = x - cx, dy = y - cy;
        return (dx * dx + dy * dy == cr * cr);
    };
    auto circle_connected = [](tuple<LL,LL,LL> c1, tuple<LL,LL,LL> c2) {
        if (get<2>(c1) > get<2>(c2)) swap(c1, c2);
        auto [x1, y1, r1] = c1;
        auto [x2, y2, r2] = c2;
        LL dx = x1 - x2, dy = y1 - y2;
        LL rsum = r1 + r2, dr = r1 - r2;
        return (dx * dx + dy * dy <= rsum * rsum) && 
            (dx * dx + dy * dy >= dr * dr);
    };

    vector<bool> vis(N, false);
    function<bool(int)> dfs = [&](int u) {
        vis[u] = true;
        if (point_on_circle(tx, ty, circle[u])) {
            return true;
        }
        for (int v = 0; v < N; v++) {
            if (!vis[v] && circle_connected(circle[u], circle[v])) {
                if (dfs(v)) return true;
            }
        }
        return false;
    };

    bool good = false;
    for (int i = 0; i < N; i++) {
        if (point_on_circle(sx, sy, circle[i])) {
            if (!vis[i]) {
                good |= dfs(i);
            }
        }
    }
    if (good) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



