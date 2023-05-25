#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    for (int guess = 0; guess <= n; guess++) {
        int liar = 0;
        for (auto x : arr) {
            liar += guess < x;
        }
        if (guess == liar) {
            cout << guess << "\n"; return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



