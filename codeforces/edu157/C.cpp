#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int dsum(string &str) {
    int ans = 0;
    for (auto ch : str) {
        ans += (ch - '0');
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<string> arr(n);
    for (auto &x : arr) cin >> x;
    map<pair<int,int>, int> full_cnt;
    for (auto x : arr) {
        full_cnt[make_pair(x.length(), dsum(x))] += 1;
    }
    LL ans = 0;
    // as left
    for (auto x : arr) {
        int sum = dsum(x), pref = 0;
        for (size_t l = 0; l < x.length(); l++) {
            pref += x[l] - '0';
            if (l + 1 > x.length() - (l + 1)) {
                pair<int,int> key(l + l + 2 - x.length(), pref + pref - sum);
                if (full_cnt.count(key) != 0) ans += full_cnt[key];
            }
        }
    }
    // as right
    for (auto x : arr) {
        int sum = dsum(x), suff = 0;
        for (int r = x.length() - 1; r >= 0; r--) {
            suff += x[r] - '0';
            if (x.length() - r > r) {
                pair<int,int> key(x.length() - r - r, suff + suff - sum);
                if (full_cnt.count(key) != 0) ans += full_cnt[key];
            }
        }
    }
    // double count pair (i, i)
    for (auto [key, cnt] : full_cnt) {
        ans -= (LL)cnt * (LL)cnt;
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

