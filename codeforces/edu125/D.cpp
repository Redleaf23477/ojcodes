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
//        cerr << ">> c = " << c << ", dh = " << dh << endl;
        for (LL money = c, it = 1; money <= C; money += c, it++) {
            if (mp[money] != -1) break;
            mp[money] = dh * it;
//            cerr << "....add " << money << " -> " << dh * it << endl;
        }
    }
    vector<T> qry;
    for (int i = 0; i <= C; i++) {
        if (mp[i] != -1) {
            LL dh = mp[i];
            if (!qry.empty()) {
                dh = max(dh, get<1>(qry.back()));
            }
            qry.emplace_back(i, dh);
        }
    }
    int q; cin >> q;
    while (q--) {
        LL D, H; cin >> D >> H;
        LL DH = D * H;
        int low = 0, high = qry.size() - 1, mid; LL ans = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            auto [c, dh] = qry[mid];
            if (dh > DH) ans = c, high = mid - 1;
            else low = mid + 1;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

