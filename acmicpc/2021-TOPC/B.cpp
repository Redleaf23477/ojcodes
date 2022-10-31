#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    const int N = 1000000;
    vector<int> sp(N+1, -1);
    iota(sp.begin(), sp.end(), 0);
    for (int i = 2; i * i <= N; i++) {
        if (sp[i] != i) continue;
        for (int j = i * i; j <= N; j += i) {
            sp[j] = i;
        }
    }
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        map<int,int> fac;
        for (int y = x; y != 1; y /= sp[y]) {
            fac[sp[y]] += 1;
        }
        LL acc = 1;
        bool too_much = false;
        for (auto [f, cnt] : fac) {
            LL tmp = 0;
            for (LL i = 0, y = 1; i <= cnt; i++, y *= f) {
                tmp += y;
            }
            acc *= tmp;
            if (acc - x > x) {
                too_much = true;
                break;
            }
        }
        acc -= x;
        if (too_much) cout << "abundant\n";
        else if (acc == x) cout << "perfect\n";
        else cout << "deficient\n";
    }
}

