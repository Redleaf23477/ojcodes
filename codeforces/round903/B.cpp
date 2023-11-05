#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool good(int cut, LL a, LL b, LL c) {
    a *= (3 + cut), b *= (3 + cut), c *= (3 + cut);
    vector<LL> arr {a, b, c};
    LL seg = (a + b + c) / (3 + cut);
    while (!arr.empty()) {
        LL &x = arr.back();
        if (x < seg) return false;
        else if (x == seg) arr.pop_back();
        else {
            if (cut == 0) return false;
            x -= seg;
            cut--;
        }
    }
    return true;
}

void solve() {
    LL a, b, c; cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << "YES\n"; return;
    }
    for (int cut = 1; cut <= 3; cut++) {
        if (good(cut, a, b, c)) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

