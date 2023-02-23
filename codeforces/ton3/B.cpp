#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        LL one = 0, zero = 0;
        char prev = 'x';
        LL max_combo = 0;
        for (LL i = 0, cnt = 0; i < n; i++) {
            char ch; cin >> ch;
            if (ch == prev) cnt++;
            else cnt = 1, prev = ch;
            max_combo = max(max_combo, cnt);
            if (ch == '0') zero++;
            else one++;
        }
        cout << max(one * zero, max_combo * max_combo) << "\n";
    }
}

