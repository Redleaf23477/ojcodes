#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

bool good(string const &str) {
    int n = str.size();
    int mid = n / 2 - (n % 2 == 0);
    for (int l = mid - (n % 2 == 1), r = mid + 1; r < n; l--, r++) {
        if (str[l] > str[r]) return false;
        else if (str[l] < str[r]) return true;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    vector<LL> fac26(n+1, 1);
    for (int i = 1; i <= n; i++) fac26[i] = fac26[i-1] * 26 % MOD;

    LL ans = 0;
    int mid = n / 2 - (n % 2 == 0);
    for (int i = 0; i <= mid; i++) {
        // I let X[i] < S[i]
        ans = (ans + (str[i] - 'A') * fac26[mid - i]) % MOD;

        // I let X[i] == S[i]
        // --> count in next iteration
    }
    if (good(str)) ans = (ans + 1) % MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



