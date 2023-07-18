#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    char s[3], t[3];
    cin >> s[0] >> s[1] >> s[2];
    cin >> t[0] >> t[1] >> t[2];
    int diff_cnt = 0;
    diff_cnt += s[0] != t[0];
    diff_cnt += s[1] != t[1];
    diff_cnt += s[2] != t[2];
    if (diff_cnt == 2) cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}



