#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL N; cin >> N;
    vector<LL> ones;
    for (int i = 0; i < 60; i++) {
        if ((N >> i) & 1) {
            ones.emplace_back(i);
        }
    }
    for (int m = 0; m < (1 << ones.size()); m++) {
        LL x = 0;
        for (int i = 0; i < (int)ones.size(); i++) {
            if ((m >> i) & 1) {
                x |= (1ll << ones[i]);
            }
        }
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

