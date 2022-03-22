#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using P = tuple<int,int>;

const int N = 51;
int dist[N][N];

bool legal(int pos) {
    return 0 <= pos && pos < N; 
}

bool is_square(int x) {
    int sq = sqrt(x);
    for (int y = -1; y <= 1; y++) {
        int t = sq + y;
        if (t * t == x) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    const int INF = N+N+N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dist[i][j] = INF;
    dist[0][0] = 0;
    queue<P> q; q.emplace(0, 0);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int d = dist[x][y];
        for (int dx = -N+1; dx < N; dx++) if (legal(x + dx)) {
            for (int dy = -N+1; dy < N; dy++) if (legal(y + dy)) {
                if (!is_square(dx * dx + dy * dy)) continue;
                int x2 = x + dx, y2 = y + dy;
                if (dist[x2][y2] == INF) {
                    dist[x2][y2] = d + 1;
                    q.emplace(x2, y2);
                }
            }
        }
    }
    int T; cin >> T;
    while (T--) {
        int x, y; cin >> x >> y;
        cout << dist[x][y] << "\n";
    }
}


