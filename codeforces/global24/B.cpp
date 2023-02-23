#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;
    LL g = arr[0];
    for (auto &x : arr) g = gcd(g, x);
    LL mx = *max_element(arr.begin(), arr.end());
    cout << mx / g << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

