#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, q; cin >> n >> q;
    string str; cin >> str;

    set<int> pos;
    for (int i = 0; i + 2 < n; i++) {
        if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C') {
            pos.insert(i);
        }
    }

    while (q--) {
        int x; cin >> x; x--;
        char ch; cin >> ch;

        // breaks old
        auto it = pos.upper_bound(x);
        if (it != pos.begin()) {
            it--;
            if (x - *it < 3 && str[x] != ch) {
                pos.erase(it);
            }
        }

        str[x] = ch;

        // builds new
        for (int i = x - 2; i <= x && i + 2 < n; i++) {
            if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C') {
                pos.insert(i);
            }
        }

        cout << pos.size() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

