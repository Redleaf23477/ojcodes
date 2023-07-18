#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    LL X; cin >> X;
    vector<pair<LL,LL>> arr(N);
    for (auto &[a, b] : arr) cin >> a >> b;
    LL ans = 4e18;
    LL sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i].first + arr[i].second;
        ans = min(ans, sum + max(0ll, (X - i - 1)) * arr[i].second);
    }
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



