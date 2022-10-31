#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<bool> lid(n);
        for (int i = 0; i < n; i++) {
            char ch; cin >> ch;
            lid[i] = (ch == '1');
        }
        LL ans = 0;
        vector<LL> book(n);
        for (int i = 0; i < n; i++) {
            cin >> book[i];
            if (lid[i]) ans += book[i];
        }
        for (int i = 0, L = -1; i < n; i++) {
            if (lid[i] == 0) L = i;
            else if (L != -1) {
                if (book[L] > book[i]) {
                    ans += book[L] - book[i];
                    L = i;
                }
            }
        }
        cout << ans << "\n";
    }
}

