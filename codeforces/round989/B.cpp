#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    n += 1;
    string str; cin >> str;
    vector<int> note(n + k + 1, 0);
    int ans = 0;
    for (int i = 0, acc = 0, pref = 0; i < n; i++) {
        pref += note[i];
        if (pref != 0) str[i] = '1';

        if (str[i] == '0') {
            acc += 1;
            if (acc == m) {
                note[i] += 1, pref += 1;
                note[i + k] -= 1;
                acc = 0;
                ans += 1;
            }
        } else {
            acc = 0;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

