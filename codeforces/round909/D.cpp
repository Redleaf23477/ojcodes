#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL get2pw(LL x) {
    LL pw = 1;
    while (x % 2 == 0) x /= 2, pw *= 2;
    return pw;
}

LL get2pw_lg(LL x) {
    LL pw = 0;
    while (x % 2 == 0) x /= 2, pw ++;
    return pw;
}

LL run(vector<LL> &box) {
    map<LL, LL> cnt;
    for (auto x : box) {
        int lg = get2pw_lg(x);
        cnt[x - lg]++;
    }
    LL ans = 0;
    for (auto [key, val] : cnt) {
        ans += val * (val - 1) / 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    map<LL,vector<LL>> box;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        LL pw = get2pw(x);
        LL k = x / pw;
        box[k].emplace_back(x);
    }
    LL ans = 0;
    for (auto [k, subbox] : box) {
        /*
        cerr << "k = " << k << ": ";
        for (auto x : subbox) cerr << x << " ";
        cerr << endl;
        */
        ans += run(subbox);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

