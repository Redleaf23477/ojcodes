#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Pt = tuple<int,int>;

const vector<int> dx {-1, 1, 0, 0}, dy {0, 0, -1, 1};
const Pt BAD_PT(-7122712, -7122712);
const int INF = 2*7122122;


int main() {
    ios::sync_with_stdio(false); cin.tie();

    int n; cin >> n;
    vector<Pt> idx2pt(n);
    map<Pt, int> pts;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pts[Pt(x, y)] = i;
        idx2pt[i] = Pt(x, y);
    }

    auto check_covered = [&](int x, int y) {
        for (int i = 0; i < 4; i++) {
            int x2 = x + dx[i], y2 = y + dy[i];
            Pt p2(x2, y2);
            if (pts.count(p2) == 0) return p2;
        }
        return BAD_PT;
    };
    auto get_dist = [](const Pt &p1, const Pt &p2) {
        auto [x1, y1] = p1;
        auto [x2, y2] = p2;
        return abs(x1 - x2) + abs(y1 - y2);
    };

    vector<Pt> ans(n, BAD_PT);
    queue<int> q;
    vector<bool> inque(n, false);
    for (int idx = 0; idx < n; idx++) {
        auto [x, y] = idx2pt[idx];
        Pt empty_pt = check_covered(x, y);
        if (empty_pt != BAD_PT) {
            q.emplace(idx), inque[idx] = true;
            ans[idx] = empty_pt;
        }
    }
    // topological sort
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        inque[u] = false;
        Pt u_pt = idx2pt[u];
        auto [x, y] = u_pt;

        if (ans[u] == BAD_PT) {
            LL min_dist = INF;
            for (int i = 0; i < 4; i++) {
                int x2 = x + dx[i], y2 = y + dy[i];
                int v = pts[Pt(x2, y2)];
                int dist = get_dist(ans[v], u_pt);
                if (dist < min_dist) {
                    min_dist = dist;
                    ans[u] = ans[v];
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int x2 = x + dx[i], y2 = y + dy[i];
            Pt p2(x2, y2);
            if (pts.count(p2) == 0) continue;
            int v = pts[p2];
            if (ans[v] != BAD_PT) continue;
            if (!inque[v]) {
                q.emplace(v), inque[v] = true;
            }
        }
        /*
        for (auto v : graph[u]) {
            if (--indeg[v] == 0) {
                q.emplace(idx2pt[v]);
            }
        }
        */
    }

    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}

