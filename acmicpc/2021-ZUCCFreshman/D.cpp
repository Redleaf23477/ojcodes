#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string str; cin >> str;
        int ans = 0;
        int len = -1;
        for (int i = 0; i < n; i++) {
            if (str[i] != 'y' && str[i] != 'b') {
                len = -1;
            }
            if (len >= 0 && str[i] == 'b') {
                len++;
                if (len >= 2) ans++;
            }
            if (len > 0 && str[i] == 'y') {
                len = 0;
            }
            if (len == -1 && str[i] == 'y') {
                len = 0;
            }
        }
        cout << ans << "\n";
    }
}

