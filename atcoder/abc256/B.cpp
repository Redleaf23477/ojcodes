#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    reverse(A.begin(), A.end());
    partial_sum(A.begin(), A.end(), A.begin());
    auto it = lower_bound(A.begin(), A.end(), 4);
    cout << A.end() - it << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



