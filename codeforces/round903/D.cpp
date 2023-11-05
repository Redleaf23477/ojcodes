#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int M = 1e6 + 1;

vector<int> sp;
void make_sp_table() {
    sp.assign(M, 0);
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i < M; i++) {
        if (sp[i] == i) {
            for (LL j = i * i; j < M; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    map<int,int> fac_cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (x != 1) {
            fac_cnt[sp[x]] += 1;
            x /= sp[x];
        }
    }
    for (auto [fac, cnt] : fac_cnt) {
        if (cnt % n != 0) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    make_sp_table();
    int T; cin >> T;
    while (T--) solve();
}

