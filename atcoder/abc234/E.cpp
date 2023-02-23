#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string X; cin >> X;
    int n = X.size();
    // same length
    for (int f = X.front() - '0'; f <= 9; f++) {
        for (int d = -9; d <= 9; d++) {
            string ans(n, '0');
            int tmp = f;
            ans.front() += tmp;
            bool good = true;
            bool greater = (f > X.front() - '0');
            for (int i = 1; i < n; i++) {
                tmp += d;
                if (tmp < 0 || tmp > 9) {
                    good = false; break;
                }
                if (!greater && tmp < X[i] - '0') {
                    good = false; break;
                }
                if (!greater && tmp > X[i] - '0') {
                    greater = true;
                }
                ans[i] += tmp;
            }
            if (good) {
                cout << ans << "\n"; return;
            }
        }
    }
    // length + 1
    if (n == 1) cout << "10\n";
    else cout << string(n+1, '1') << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

