#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    int mex = 0;
    for (auto x : A) if (x == mex) mex++;
    cout << mex << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



