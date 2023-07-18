#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    if (n == 1) cout << 1 << "\n";
    else if (n == 2) cout << 2 << " " << 1 << "\n";
    else {
        vector<int> ans(n, 0);
        ans[n / 2] = 1;
        ans.back() = 2;
        ans.front() = 3;
        int num = 4;
        for (auto &x : ans) {
            if (x == 0) x = num++;
        }
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    //    int T = 1;
    while (T--) {
        solve();
    }
}



