#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int pre1_num(string s) {
    int ans = 0;
    for (auto ch : s) {
        if (ch == '1') ans++;
        else break;
    }
    return ans;
}

void solve() {
    string s; cin >> s;
    LL longest = 0, cnt = 0;
    for (auto ch : s) {
        if (ch == '0') {
            cnt = 0;
        } else {
            cnt++;
            longest = max(longest, cnt);
        }
    }

    LL L = pre1_num(s);
    reverse(s.begin(), s.end());
    LL R = pre1_num(s);
    if (L != s.size()) {
        longest = max(longest, L + R);
    }

    LL ans = 0;
    
    if (longest == s.size()) {
        ans = longest * longest;
    } else {
        LL a = (1 + longest) / 2, b = 1 + longest - a;
        ans = a * b;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



