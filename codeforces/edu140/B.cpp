#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL tower; cin >> tower;
    vector<LL> arr(n-1);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    for (auto x : arr) {
        if (tower >= x) continue;
        tower = x + tower - (x + tower) / 2;
    }
    cout << tower << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

