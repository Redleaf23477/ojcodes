#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<vector<pair<int,int>>> arr(N);
    map<int,pair<int,int>> fac;
    for (int i = 0; i < N; i++) {
        int m; cin >> m;
        while (m--) {
            int p, cnt; cin >> p >> cnt;
            arr[i].emplace_back(p, cnt);
            auto it = fac.find(p);
            if (it == fac.end()) {
                fac[p] = make_pair(cnt, 1);
            } else if (cnt > it->second.first) {
                fac[p] = make_pair(cnt, 1);
            } else if (cnt == it->second.first) {
                fac[p].second++;
            }
        }
    }
    
    int ans = 0;
    bool has_same = false;
    for (int i = 0; i < N; i++) {
        bool same = true;
        for (auto [p, cnt] : arr[i]) {
            if (fac[p].first == cnt && fac[p].second == 1) {
                same = false;
            }
        }
        if (same) has_same = true;
        if (!same) ans++;
    }
    cout << ans + has_same << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



