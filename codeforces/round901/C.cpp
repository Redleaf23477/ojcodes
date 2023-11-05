#include <bits/stdc++.h>
using namespace std;
using LL = long long;

string get_bit(LL n, LL lgm) {
    string str(lgm, '0');
    for (auto &ch : str) {
        ch += n % 2;
        n /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}

void solve() {
    LL n, m; cin >> n >> m;
    n %= m;
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    LL g = gcd(n, m);
    if (__builtin_popcount(m / g) != 1) {
        cout << -1 << "\n";
        return;
    }
    LL ans = 0, piece = n;
    string bit = get_bit(n / g, __lg(m / g));
    for (auto ch : bit) {
        ans += piece;
        piece *= 2;
        if (ch == '1') {
            piece -= m;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
}

