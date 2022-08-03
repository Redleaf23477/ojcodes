#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    const int N = 20;
    vector<vector<LL>> cnt(N, vector<LL>(N, 0));
    int n; cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        int a = str[0] - 'a', b = str[1] - 'a';
        for (int i = 0; i < N; i++) {
            ans += cnt[a][i];
            ans += cnt[i][b];
        }
        ans -= 2 * cnt[a][b];

        // add to set
        cnt[a][b] += 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

