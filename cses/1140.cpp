#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;
using T = tuple<int,int,LL>;

void relabel(vector<T> &arr) {
    int n = arr.size();
    vector<int> tmp(2*n);
    for (int i = 0; i < n; i++) {
        auto [l, r, val] = arr[i];
        tmp[2 * i] = l;
        tmp[2 * i + 1] = r;
    }
    sort(tmp.begin(), tmp.end());
    auto it = unique(tmp.begin(), tmp.end());
    tmp.erase(it, tmp.end());

    for (auto &[l, r, val] : arr) {
        l = lower_bound(tmp.begin(), tmp.end(), l) - tmp.begin() + 1;
        r = lower_bound(tmp.begin(), tmp.end(), r) - tmp.begin() + 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<T> arr(n); 
    for (auto &[l, r, val] : arr) {
        cin >> l >> r >> val;
    }
    relabel(arr);

    sort(arr.begin(), arr.end(), [](const T &lhs, const T &rhs) {
        return get<1>(lhs) < get<1>(rhs);
    });

    vector<LL> dp(2*n+1, 0);
    for (int i = 0, L = 1; i < n; i++) {
        auto [l, r, val] = arr[i];
        for (; L < r; L++) dp[L] = max(dp[L], dp[L-1]);
        dp[r] = max(dp[r], dp[l-1] + val);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}