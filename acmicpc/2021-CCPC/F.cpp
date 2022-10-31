#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n); 
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end(), greater<LL>());
    LL x; cin >> x;

    vector<LL> cand {x};
    for (auto m : arr) {
        vector<LL> tmp;
        for (auto c : cand) {
            tmp.emplace_back(c % m);
        }
        cand.insert(cand.end(), tmp.begin(), tmp.end());
    }

    LL ans = 0;
    for (auto c : cand) {
        ans = max(ans, c % arr.back());
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

