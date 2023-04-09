#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    constexpr int full = 2048;
    int n, t; cin >> n >> t;
    vector<vector<int>> glass(n + 1, vector<int>(n + 1, 0));
    for (int sim = 0; sim < t; sim++) {
        glass[0][0] += full;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (glass[i][j] >= full) {
                    int more = glass[i][j] - full;
                    glass[i][j] = full;
                    int l = j, r = j + 1;
                    glass[i+1][l] += more / 2;
                    glass[i+1][r] += more / 2;
                    assert(more / 2 * 2 == more);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            ans += (glass[i][j] == full);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



