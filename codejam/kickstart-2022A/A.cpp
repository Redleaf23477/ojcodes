#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool ok(const string &I, const string &P) {
    for (auto i = I.begin(), p = P.begin(); i != I.end(); i++, p++) {
        while (p != P.end() && *i != *p) p++;
        if (p == P.end()) return false;
    }
    return true;
}

void solve() {
    string I, P; cin >> I >> P;
    if (ok(I, P)) cout << P.size() - I.size() << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

