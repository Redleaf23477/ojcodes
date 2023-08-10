#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int S, T, M; cin >> S >> T >> M;
    vector<vector<int>> graph(S + T);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<vector<int>> point(T, vector<int>(T, -1));
    for (int u = 0; u < S; u++) {
        for (size_t i = 0; i < graph[u].size(); i++) {
            for (size_t j = i + 1; j < graph[u].size(); j++) {
                int x = graph[u][i] - S, y = graph[u][j] - S;
                if (point[x][y] == -1) {
                    point[x][y] = point[y][x] = u;
                } else {
                    cout << u + 1 << " " << S + x + 1 << " " << point[x][y] + 1 << " " << S + y + 1 << "\n";
                    return;
                }
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



