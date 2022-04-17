#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string str; cin >> str;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (i > 1 && str[i-2] == '0' && str[i-1] == '1' && str[i] == '0') ans += 1;
            if (str[i-1] == '0' && str[i] == '0') ans += 2;
        }
        cout << ans << "\n";
    }
}

