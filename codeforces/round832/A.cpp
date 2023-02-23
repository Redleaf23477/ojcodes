#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        LL s1 = 0, s2 = 0;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x > 0) s1 += x;
            else s2 -= x;
        }
        cout << max(s1 - s2, s2 - s1) << "\n";
    }
}

