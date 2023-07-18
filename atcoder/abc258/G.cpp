#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<bitset<3000>> G(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch; cin >> ch;
            if (ch == '1' && i != j) G[i][j] = true;
        }
    }
    LL ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (G[i][j]) ans += (G[i] & G[j]).count();
        }
    }
    cout << ans / 3 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



