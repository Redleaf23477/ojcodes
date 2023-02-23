#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(m);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end(), greater<int>());
    int rem = n % k;
    for (auto x : arr) {
        if (x > n / k + 1) {
            cout << "NO\n"; return;
        } else if (x == n / k + 1) {
            if (rem == 0) {
                cout << "NO\n"; return;
            } else {
                rem--;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

