#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    bool zero = (arr[0] == 0);
    bool one = binary_search(arr.begin(), arr.end(), 1);

    if (zero && one) { cout << "NO\n"; }
    else if (one) {
        bool ans = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i-1] == 1) ans = false;
        }
        cout << (ans? "YES\n" : "NO\n");
    } else { cout << "YES\n"; }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

