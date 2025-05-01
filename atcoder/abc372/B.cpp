#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int B; cin >> B;
    vector<int> ans;
    int pw = 1;
    for (int i = 0; i < 10; i++) pw *= 3;

    for (int i = 10; i >= 0; i--) {
        int q = B / pw;
        while (q--) ans.emplace_back(i);
        B %= pw;
        pw /= 3;
    }

    cout << ans.size() << "\n";
    for (auto &x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

