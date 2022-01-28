#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL k; cin >> k;
    using T = tuple<LL,LL>;
    vector<T> arr(n); 
    for (auto &[a, b] : arr) cin >> a;
    for (auto &[a, b] : arr) cin >> b;
    sort(arr.begin(), arr.end());

    for (auto [a, b] : arr) {
        if (k >= a) k += b;
        else break;
    }

    cout << k << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

