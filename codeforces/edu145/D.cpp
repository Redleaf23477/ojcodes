#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL E12 = 1e12;

void solve() {
    string str; cin >> str;
    LL n = str.size();
    vector<LL> one_pos;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') one_pos.emplace_back(i);
    }
    for (int i = one_pos.size() - 2; i >= 0; i--) {
        one_pos[i] += one_pos[i+1];
    }
    LL ans = one_pos.size() * (E12 + 1);
    for (LL kill = 0; kill < one_pos.size(); kill++) {
        LL left = one_pos.size() - kill;
        // swap = (n-1 + n-2 + ... + n-left) - suff(n-1, ..., n-left)
        LL swap = ((n+n-1-left) * left / 2) - (left == 0? 0 : one_pos[one_pos.size() - left]);
        LL cost = kill * (E12 + 1) + swap * E12;
        ans = min(ans, cost);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



