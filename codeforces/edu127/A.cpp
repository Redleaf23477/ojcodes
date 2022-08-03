#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        int n = str.size();
        bool ans = true;
        int cnt = 1;
        char prv = str[0];
        for (int i = 1; i < n; i++) {
            if (str[i] != prv) {
                if (cnt == 1) ans = false;
                cnt = 1;
            } else {
                cnt += 1;
            }
            prv = str[i];
        }
        ans = ans && (cnt > 1);
        cout << (ans? "YES\n" : "NO\n");
    }
}

