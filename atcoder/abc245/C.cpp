#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    bool good[2] = {true, true};
    for (int i = 1; i < n; i++) {
        bool good_A = false, good_B = false;
        if (abs(A[i] - A[i-1]) <= k && good[0]) good_A = true;
        if (abs(A[i] - B[i-1]) <= k && good[1]) good_A = true;
        if (abs(B[i] - A[i-1]) <= k && good[0]) good_B = true;
        if (abs(B[i] - B[i-1]) <= k && good[1]) good_B = true;
        good[0] = good_A, good[1] = good_B;
    }
    if (good[0] || good[1]) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



