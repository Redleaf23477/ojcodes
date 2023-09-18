#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    vector<int> bit_cnt(32, 0);
    int xor_sum = 0;
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m);
    for (auto &x : A) {
        cin >> x;
        xor_sum ^= x;
    }
    for (auto &x : B) cin >> x;
    int mn_ans = xor_sum;
    int mx_ans = xor_sum;
    if (n % 2 == 0) {
        for (auto x : B) {
            for (int b = 0; b < 32; b++) {
                if ((x >> b) & 1) {
                    if ((mn_ans >> b) & 1) {
                        mn_ans ^= (1 << b);
                    }
                }
            }
        }
    } else {
        for (auto x : B) {
            for (int b = 0; b < 32; b++) {
                if ((x >> b) & 1) {
                    if (((mx_ans >> b) & 1) == 0) {
                        mx_ans ^= (1 << b);
                    }
                }
            }
        }
    }
    cout << mn_ans << " " << mx_ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

