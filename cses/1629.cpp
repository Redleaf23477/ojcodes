#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    using T = tuple<int,int>;
    vector<T> arr(n);
    for (auto &[l, r] : arr) {
        cin >> l >> r;
    }
    sort(arr.begin(), arr.end(), [](const T &lhs, const T &rhs) {
        const auto &[l1, r1] = lhs;
        const auto &[l2, r2] = rhs;
        if (r1 != r2) return r1 < r2;
        else return l1 < l2;
    });
    int ans = 0, e = 0;
    for (auto [l, r] : arr) {
        if (e <= l) {
            e = r;
            ans += 1;
        }
    }
    cout << ans << endl;
}

