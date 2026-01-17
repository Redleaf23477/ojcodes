#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    size_t n; cin >> n;
    size_t k; cin >> k; k = n - k;
    LL x; cin >> x;
    vector<LL> a(n); {
        for (auto &ai : a) cin >> ai;
        sort(a.begin(), a.end());
    }

    size_t acc = k;
    LL sake = 0;
    for (int i = n - k - 1; i >= 0 && sake < x; i--) {
        acc += 1;
        sake += a[i];
    }

    if (sake >= x) {
        cout << acc << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

