#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<LL,LL>;  // (cost, d*h)

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    LL C; cin >> C;
    vector<T> arr(n);
    for (auto &[c, dh] : arr) {
        LL d, h;
        cin >> c >> d >> h;
        dh = d * h;
    }
    sort(arr.begin(), arr.end(), [](const T &lhs, const T &rhs) {
        auto [l_c, l_dh] = lhs;
        auto [r_c, r_dh] = rhs;
        // l_dh / l_c > r_dh / r_c
        return l_dh * r_c > l_c * r_dh;
    });
    vector<LL> mp(C+1, -1);
    for (auto [c, dh] : arr) {
        mp[c] = max(mp[c], dh);
    }
    for (int c = 1; c <= C; c++) {
        if (mp[c] == -1) continue;
        for (int d = c + c, it = 2; d <= C; d += c, it++) {
            mp[d] = max(mp[d], mp[c] * it);
        }
    }
    for (int c = 1; c <= C; c++) {
        mp[c] = max(mp[c], mp[c-1]);
    }
    int q; cin >> q;
    while (q--) {
        LL D, H; cin >> D >> H;
        LL DH = D * H;
        int low = 0, high = C; LL ans = -1;
        while (low <= high) {
            LL c = (low + high) / 2;
            LL dh = mp[c];
            if (dh > DH) ans = c, high = c - 1;
            else low = c + 1;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

