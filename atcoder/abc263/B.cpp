#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<int> P(N);
    for (int i = 1; i < N; i++) { cin >> P[i]; P[i]--; }
    int ans = 0, x = N - 1;
    while (x != 0) x = P[x], ans++;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



