#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M; cin >> N >> M;
    vector<LL> S(N - 1);
    for (auto &s : S) cin >> s;
    vector<LL> X(M);
    for (auto &x : X) cin >> x;

    vector<LL> fac(N, 0);
    for (int i = 1; i < N; i++) {
        fac[i] = S[i - 1] - fac[i - 1];
    }

    map<LL,int> z;
    for (int i = 0; i < N; i++) {
        for (auto x : X) {
            // (-1)^i z + fac[i] = x
            LL val = x - fac[i];
            if (i % 2 == 1) val *= -1;
            z[val]++;
        }
    }
    int mx = 0;
    for (auto [val, cnt] : z) {
        mx = max(mx, cnt);
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



