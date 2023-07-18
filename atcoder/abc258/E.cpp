#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, Q; cin >> N >> Q;
    LL X; cin >> X;
    vector<LL> W(N), pref_W(N);
    for (auto &x : W) cin >> x;
    partial_sum(W.begin(), W.end(), pref_W.begin());

    vector<int> sz(N);
    for (int i = 0; i < N; i++) {
        LL head = (i != 0? pref_W[i - 1] : 0);
        LL tail = pref_W.back() - head;
        if (tail >= X) {
            sz[i] = lower_bound(pref_W.begin() + i, pref_W.end(), X + head) - (pref_W.begin() + i) + 1;
        } else {
            sz[i] = N - i;
            sz[i] += (X - tail) / pref_W.back() * N;
            LL rem = (X - tail) % pref_W.back();
            if (rem > 0) {
                sz[i] += lower_bound(pref_W.begin(), pref_W.end(), rem) - pref_W.begin() + 1;
            }
        }
    }

    vector<bool> vis(N, false);
    vector<int> seq {0};
    vis[0] = true;
    int cyc_start = -1;
    while (true) {
        int u = seq.back();
        int nxt = (u + sz[u]) % N;
        if (vis[nxt]) {
            cyc_start = nxt;
            break;
        }
        seq.emplace_back(nxt);
        vis[nxt] = true;
    }
    int head_len = find(seq.begin(), seq.end(), cyc_start) - seq.begin();
    int cyc_len = seq.size() - head_len;

    while (Q--) {
        LL K; cin >> K; K--;
        if (K < head_len) {
            cout << sz[seq[K]] << "\n";
        } else {
            K = (K - head_len) % cyc_len;
            cout << sz[seq[head_len + K]] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



