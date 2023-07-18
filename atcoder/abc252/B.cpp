#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n), B(k);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    int mx = *max_element(A.begin(), A.end());
    bool good = false;
    for (auto b : B) {
        if (A[b-1] == mx) good = true;
    }
    cout << (good? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



