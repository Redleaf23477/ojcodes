#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using P = pair<LL,LL>;
using T = tuple<LL,LL,LL>;

void solve() {
    LL R, C; cin >> R >> C;
    int n; cin >> n;
    P start; cin >> start.first >> start.second;
    P ending; cin >> ending.first >> ending.second;
    map<int,vector<LL>> rows;
    map<int,vector<LL>> cols;
    for (int i = 0; i < n; i++) {
        int r, c; cin >> r >> c;
        rows[r].emplace_back(c);
        cols[c].emplace_back(r);
    }
    for (auto &[_, arr] : rows) sort(arr.begin(), arr.end());
    for (auto &[_, arr] : cols) sort(arr.begin(), arr.end());

    // dijkstra
    map<P, LL> dist;
    priority_queue<T, vector<T>, greater<T>> PQ;

    auto update_dir = [&dist, &PQ](map<int, vector<LL>> &cols, LL c, LL r, LL len, bool rot = false) {
        // up, down (and similarly for left, right)
        if (cols.count(c) != 0) {
            auto &arr = cols[c];
            auto it = upper_bound(arr.begin(), arr.end(), r);
            if (it != arr.end()) {
                LL down_r = *it - 1;
                LL next_len = len + 1;
                if (down_r != r) {
                    P next_p = (rot? P(c, down_r) : P(down_r, c));
                    T next_t = (rot? T(next_len, c, down_r) : T(next_len, down_r, c));
                    auto tmp_it = dist.find(next_p);
                    if (tmp_it == dist.end() || tmp_it->second > next_len) {
                        dist[next_p] = next_len;
                        PQ.emplace(next_t);
                    }
                }
            }
            if (it != arr.begin()) {
                it--;
                LL up_r = *it + 1;
                LL next_len = len + 1;
                if (up_r != r) {
                    P next_p = (rot? P(c, up_r) : P(up_r, c));
                    T next_t = (rot? T(next_len, c, up_r) : T(next_len, up_r, c));
                    auto tmp_it = dist.find(next_p);
                    if (tmp_it == dist.end() || tmp_it->second > next_len) {
                        dist[next_p] = next_len;
                        PQ.emplace(next_t);
                    }
                }
            }
        }
    };

    dist[start] = 0;
    PQ.emplace(0, start.first, start.second);
    while (!PQ.empty()) {
        auto [len, r, c] = PQ.top(); PQ.pop();
        P cur(r, c);
        if (len > dist[cur]) continue;

        if (cur == ending) {
            cout << len << "\n"; return;
        }
        // up, down
        update_dir(cols, c, r, len, false);
        // left, right
        update_dir(rows, r, c, len, true);
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



