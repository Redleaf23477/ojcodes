#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
LL INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    if (n % 2 == 1) {
        cout << "Yes\n"; return;
    }
    LL lb = 0, ub = arr[n-1] - arr[n-2];
    for (int i = 0, s = 1; i < n-2; i++, s *= -1) {
        lb += s * arr[i];
    }
    if (lb <= ub) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



