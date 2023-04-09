#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool is_zero(int n, LL k, vector<LL> const fac) {
    LL sum = 0;
    for (auto f : fac) {
        sum += f;
        if (sum % k != 0) return false;
        sum /= k;
    }
    return sum == 0;
}

void solve() {
    int n; cin >> n;
    LL k; cin >> k;
    vector<LL> fac(n+1, -87);
    int unset_cnt = 0;
    for (int i = 0; i <= n; i++) {
        string s; cin >> s;
        if (s[0] == '?') {
            unset_cnt++;
        } else {
            fac[i] = stoll(s);
        }
    }
    if (unset_cnt == 0) {
        if (k == 0) cout << (fac[0] == 0? "Yes\n" : "No\n");
        else if (is_zero(n, k, fac)) cout << "Yes\n";
        else cout << "No\n";
    } else {
        bool me_last = (n + 1) % 2 == 0;
        bool me_first = (n + 1 - unset_cnt) % 2 == 1;
        if (me_first && fac[0] == -87) fac[0] = 0;

        if (k == 0) cout << (fac[0] == 0? "Yes\n" : "No\n");
        else if (me_last) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



