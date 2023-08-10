#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int level; cin >> level;
    int X, Y; cin >> X >> Y;
    LL red = 1, blue = 0;
    while (level > 1) {
        tie(red, blue) = make_pair(red + red * X + blue, (red * X + blue) * Y);
        level--;
    }
    cout << blue << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



