#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using IT = vector<int>::iterator;

LL calc(IT L, IT R, int X, int Y) {
    vector<IT> x_pos, y_pos;
    for (auto it = L; it != R; it++) {
        if (*it == X) x_pos.emplace_back(it);
        if (*it == Y) y_pos.emplace_back(it);
    }
    LL ans = 0;
    for (auto it = L; it != R; it++) {
        auto x_lb = lower_bound(x_pos.begin(), x_pos.end(), it);
        auto y_lb = lower_bound(y_pos.begin(), y_pos.end(), it);
        if (x_lb == x_pos.end() || y_lb == y_pos.end()) break;
        ans += R - max(*x_lb, *y_lb);
    }
    return ans;
}

void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> arr(N);
    for (auto &x : arr) cin >> x;

    LL ans = 0;
    IT L, R;
    for (L = R = arr.begin(); R != arr.end(); R++) {
        if (*R < Y || *R > X) {
            ans += calc(L, R, X, Y);
            L = R + 1;
        }
    }
    ans += calc(L, R, X, Y);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



