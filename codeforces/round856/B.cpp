#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    if (arr[0] == 1) arr[0]++;
    for (int i = 1; i < n; i++) {
        if (arr[i] == 1) arr[i]++;
        if (arr[i] % arr[i-1] == 0) {
            arr[i]++;
        }
    }
    for (auto x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



