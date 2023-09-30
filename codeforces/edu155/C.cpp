#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL MOD = 998244353;

void solve() {
    string str; cin >> str;
    // (len, op_cnt)
    pair<LL,LL> end_0(0, 1), end_1(0, 1);
    for (auto ch : str) {
        pair<LL,LL> next_0(0, 0), next_1(0, 0);
        if (ch == '0') {
            if (end_0.first + 1 == end_1.first) {
                next_0 = make_pair(end_0.first + 1, (end_0.second * (end_0.first + 1) + end_1.second) % MOD);
            } else if (end_0.first + 1 < end_1.first) {
                next_0 = make_pair(end_0.first + 1, end_0.second * (end_0.first + 1) % MOD);
            } else {
                next_0 = end_1;
            }

            next_1 = make_pair(end_1.first + 1, end_1.second * (end_1.first + 1) % MOD);
        } else {
            if (end_0.first == end_1.first + 1) {
                next_1 = make_pair(end_0.first, (end_0.second + end_1.second * (end_1.first + 1)) % MOD);
            } else if (end_0.first < end_1.first + 1) {
                next_1 = end_0;
            } else {
                next_1 = make_pair(end_1.first + 1, end_1.second * (end_1.first + 1) % MOD);
            }

            next_0 = make_pair(end_0.first + 1, end_0.second * (end_0.first + 1) % MOD);
        }
        end_0 = next_0, end_1 = next_1;
    }
    if (end_0.first == end_1.first) {
        cout << end_0.first << " " << (end_0.second + end_1.second) % MOD << "\n";
    } else if (end_0.first < end_1.first) {
        cout << end_0.first << " " << end_0.second << "\n";
    } else {
        cout << end_1.first << " " << end_1.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

