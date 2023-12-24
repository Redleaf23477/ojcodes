#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    if (n == 1) {
        cout << 1 << "\n"; return;
    }

    LL x = 0;
    for (int i = 1; i < n; i++) {
        x = gcd(x, arr[i] - arr[i - 1]);
    }
    // cerr << "x = " << x << endl;

    LL op_cnt = 0;
    for (auto elem : arr) {
        op_cnt += (arr.back() - elem) / x;
    }
    // cerr << "op_cnt = " << op_cnt << endl;

    // add the last element
    for (int k = 1; k <= n; k++) {
        LL new_elem = arr.back() - x * k;
        if (!binary_search(arr.begin(), arr.end(), new_elem)) {
            op_cnt += k;
            break;
        }
    }

    cout << op_cnt << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

