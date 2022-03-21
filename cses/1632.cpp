#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, k; cin >> n >> k;
    vector<T> arr(n);
    for (auto &[l, r] : arr) cin >> l >> r;
    sort(arr.begin(), arr.end(), [](const T &lhs, const T &rhs) {
        auto [l1, r1] = lhs;
        auto [l2, r2] = rhs;
        if (r1 != r2) return r1 < r2;
        else return l1 < l2;
    });
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < k; i++) s.insert(0);
    for (auto [l, r] : arr) {
        auto it = s.upper_bound(l);
        if (it == s.begin()) continue;
        it--;
        s.erase(it);
        s.insert(r);
        ans += 1;
    }
    cout << ans << "\n";
}

