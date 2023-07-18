#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL N; cin >> N;

    vector<int> sp(N + 1);
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i <= N; i++) {
        if (sp[i] != i) continue;
        for (LL j = i * i; j <= N; j += i) {
            if (sp[j] == j) sp[j] = i;
        }
    }
    auto defac = [&](int x) {
        map<int,int> ans;
        while (x > 1) {
            ans[sp[x]]++;
            x /= sp[x];
        }
        return ans;
    };

    vector<LL> sq(N);
    for (LL i = 1; i <= N; i++) {
        sq[i - 1] = i * i;
    }

    LL ans = 0;
    for (LL i = 1; i <= N; i++) {
        LL tmp = 1;
        auto fac = defac(i);
        for (auto [f, cnt] : fac) {
            if (cnt % 2 == 1) tmp *= f;
        }
        ans += upper_bound(sq.begin(), sq.end(), N / tmp) - sq.begin();
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



