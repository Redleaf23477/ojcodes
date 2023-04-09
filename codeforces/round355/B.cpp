#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n; 
    LL h, k; cin >> h >> k;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    arr.emplace_back(h);

    LL ans = 0, buffer = 0;
    for (int i = 0; i < n; i++) {
        buffer += arr[i];
        LL nxt_buffer = h - arr[i+1];
        if (buffer > nxt_buffer) {
            LL delta = buffer - nxt_buffer;
            LL smash = (delta + k - 1) / k;
            ans += smash;
            buffer = max(0ll, buffer - smash * k);
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



