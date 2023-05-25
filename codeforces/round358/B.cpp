#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    int mex = 1;
    for (auto x : arr) {
        if (x >= mex) {
            mex++;
        }
    }
    cout << mex << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



