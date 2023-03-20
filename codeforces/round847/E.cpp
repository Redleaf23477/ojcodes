#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

pair<LL,LL> test(LL x, LL sum) {
    sum -= x;
    LL a = x; 
    LL b = 0;
    for (LL i = 31; i >= 0; i--) {
        if ((x >> i) & 1) {
            continue;
        } else {
            if ((2 * (1ll << i)) <= sum) {
                a |= (1ll << i);
                b |= (1ll << i);
                sum -= 2 * (1ll << i);
            }
        }
    }
    if (0 == sum) return make_pair(a, b);
    else return make_pair(-1, -1);
}

void solve() {
    LL x; cin >> x;
    auto [a, b] = test(x, x * 2 + 0);
    if (b != -1) {
        cout << a << " " << b << "\n"; return;
    }
    tie(a, b) = test(x, x * 2 + 1);
    if (b != -1) {
        cout << a << " " << b << "\n"; return;
    } else {
        cout << -1 << "\n"; return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



