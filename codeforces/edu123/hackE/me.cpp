#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool same(const string &str) {
    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] != str[i-1]) return false;
    }
    return true;
}

void flip(string &str) {
    for (auto &x : str) {
        if (x == 'R') x = 'D';
        else x = 'R';
    }
}

LL prefix_len(const string &str) {
    LL ans = 1;
    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] != str[0]) break;
        ans++;
    }
    return ans;
}

LL count_D(const string &str) {
    LL ans = 0;
    for (auto c : str) ans += (c == 'D');
    return ans;
}

LL partUR(const string &str, const LL plen) {
    LL ans = 0;
    LL bye = plen;
    for (size_t i = plen; i < str.size(); i++) {
        if (str[i] == 'R') bye -= 1;
        else ans += bye;
    }
    return ans;
}

LL part(const string &str, const char A, const char B) {
    // find first D
    LL fd;
    for (fd = 0; fd < (LL)str.size(); fd++) {
        if (str[fd] == A) break;
    }
    // find last D
    LL ld;
    for (ld = str.size() - 1; ld >= 0; ld--) {
        if (str[ld] == A) break;
    }
    // count R between them
    LL bye = 0;
    for (int i = fd; i < ld; i++) {
        bye += (str[i] == B);
    }
    // count
    LL ans = 0;
    for (int i = ld; i >= fd; i--) {
        if (str[i] == A) ans += bye;
        else bye -= 1;
    }
    return ans;
}

void solve() {
    LL n; cin >> n;
    string str; cin >> str;
    if (same(str)) { cout << n << "\n"; return; }
    if (str[0] == 'D') flip(str);

    LL ans = n * n;
    LL plen = prefix_len(str);
    // part D
    ans -= (n-1) * plen;
    // part UR
    ans -= part(str, 'R', 'D');
    // part DL
    ans -= part(str, 'D', 'R');

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

