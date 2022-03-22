#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int ans = 0, rem = n;
    char state = 'x';  // 'x', '(', ')'
    for (int i = 0; i < n; i++) {
        if (state == 'x') state = str[i];
        else if (state == '(') {
            state = 'x', ans += 1, rem -= 2;
        } else {
            if (str[i] == ')') {
                state = 'x', ans += 1, rem = n - i - 1;
            }
        }
    }
    cout << ans << " " << rem << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

