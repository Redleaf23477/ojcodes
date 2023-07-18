#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL,int>;
constexpr LL INF = 1e18;

/*
 *          |     |      |     |
 *  Y0    -18-----19----10--11-12-
 *          |     |      |  |  |
 *  Y1      |     |     13--9--14
 *          |     |      |  |  | 
 *  Y2    -20-----21----15--16-17-
 *          |     |      |     |
 *          |     |      |     |
 *          |     |      |     |
 *          |     |      |     |
 *  Y3    --1--2--3-----22-----23-
 *          |  |  |      |     |
 *  Y4      4--0--5      |     |
 *          |  |  |      |     | 
 *  Y5    --6--7--8-----24-----25-
 *          |     |      |     |
 *
 *         X0 X1 X2     X3 X4 X5
 *
 */

void solve() {
    LL B, K, Sx, Sy, Gx, Gy; 
    cin >> B >> K >> Sx >> Sy >> Gx >> Gy;

    vector<LL> X(6), Y(6);
    X[1] = max(Sx, Gx);
    X[4] = min(Sx, Gx);
    X[0] = X[1] / B * B;
    X[2] = X[0] + B;
    X[3] = X[4] / B * B;
    X[5] = X[3] + B;

    Y[1] = max(Sy, Gy);
    Y[4] = min(Sy, Gy);
    Y[0] = Y[1] / B * B;
    Y[2] = Y[0] + B;
    Y[3] = Y[4] / B * B;
    Y[5] = Y[3] + B;

    pair<int,int> S(Sx == X[1]? 1 : 4, Sy == Y[1]? 1 : 4);
    pair<int,int> G(Gx == X[1]? 1 : 4, Gy == Y[1]? 1 : 4);

    vector<LL> dist(36, INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    dist[S.first * 6 + S.second] = 0;
    pq.emplace(0, S.first * 6 + S.second);
    while (!pq.empty()) {
        auto [len, idx] = pq.top(); pq.pop();
        if (len > dist[idx]) continue;
        if (idx == G.first * 6 + G.second) {
            cout << len << "\n"; return;
        }
        int i = idx / 6, j = idx % 6;
        // move i
        for (int i2 = 0; i2 < 6; i2++) {
            int idx2 = i2 * 6 + j;
            LL di = abs(X[i] - X[i2]);
            LL len2 = len + di * (Y[j] % B == 0? 1 : K);
            if (len2 < dist[idx2]) {
                dist[idx2] = len2;
                pq.emplace(len2, idx2);
            }
        }
        // move j
        for (int j2 = 0; j2 < 6; j2++) {
            int idx2 = i * 6 + j2;
            LL dj = abs(Y[j] - Y[j2]);
            LL len2 = len + dj * (X[i] % B == 0? 1 : K);
            if (len2 < dist[idx2]) {
                dist[idx2] = len2;
                pq.emplace(len2, idx2);
            }
        }
    }

    cout << -1 << "\n"; // unreachable
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



