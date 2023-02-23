#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL L, N; cin >> L >> N;
    vector<pair<LL,char>> arr(N);
    for (auto &[D, C] : arr) cin >> D >> C;

    LL ans = 0;
    LL pos = 0;
    char dir = arr[0].second;
    for (auto [D, C] : arr) {
        if (C == dir) {
            // go to starting line
            if (pos + D >= L) {
                D -= L - pos, ans += 1, pos = 0;
            }
            // update laps
            ans += D / L;
            // update position
            pos += D % L;
        } else {
            // go to starting line
            if (pos <= D) {
                D -= pos, pos = 0, dir = C;
                // update laps
                ans += D / L;
                // update position
                pos += D % L;
            } else {
                pos -= D;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

