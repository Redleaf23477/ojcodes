#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<LL> uniq_and_count(vector<int> &arr) {
    vector<int> tmp(arr);
    sort(tmp.begin(), tmp.end());
    auto it = unique(tmp.begin(), tmp.end());
    tmp.erase(it, tmp.end());
    vector<LL> cnt(tmp.size());
    for (auto x : arr) {
        auto it = lower_bound(tmp.begin(), tmp.end(), x);
        cnt[it - tmp.begin()]++;
    }
    return cnt;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<LL> cnt = uniq_and_count(arr);
    int m = cnt.size();
    vector<LL> suff(cnt);
    for (int i = m - 2; i >= 0; i--) {
        suff[i] += suff[i+1];
    }
    vector<LL> two(m, 0);
    for (int i = m - 2; i >= 0; i--) {
        two[i] = cnt[i] * suff[i+1];
        two[i] += two[i+1];
    }
    vector<LL> three(cnt.size(), 0);
    for (int i = m - 2; i >= 0; i--) {
        three[i] = cnt[i] * two[i+1];
    }
    cout << accumulate(three.begin(), three.end(), 0ll) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



