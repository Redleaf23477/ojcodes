#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Edge = tuple<LL, size_t>;

void solve() {
    size_t n, m, l; cin >> n >> m >> l;
    LL s, t; cin >> s >> t;

    vector<vector<Edge>> graph(n); {
        for (size_t _ = 0; _ < m; _++) {
            size_t u, v; cin >> u >> v; u--, v--;
            size_t c; cin >> c;
            graph[u].emplace_back(c, v);
        }
    }

    // map[i][j] = k: i = ending, j = length, k = count
    map<size_t, map<LL, size_t>> mp; {
        mp[0][0] = 1;
    }
    while (l--) {
        map<size_t, map<LL, size_t>> nxt_mp;

        for (const auto &[u, path] : mp) {
            for (auto [len, cnt] : path) {
                for (auto [c, v] : graph[u]) {
                    if (len + c > t) {
                        continue;
                    }
                    nxt_mp[v][len + c] += cnt;
                }
            }
        }

        mp = std::move(nxt_mp);
    }

    for (const auto &[u, path] : mp) {
        auto lb = path.lower_bound(s);
        if (lb == path.end()) {
            continue;
        }
        cout << u + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

