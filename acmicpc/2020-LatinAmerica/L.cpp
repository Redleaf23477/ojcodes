#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using TII = tuple<int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<TII> activity(n);
    for (auto &[s, d] : activity) cin >> s >> d;

    auto run = [&](int start) {
        int acc = 0;
        for (auto [s, d] : activity) {
            int l = s, r = s + d;  // [l, r]
            if (r < start) continue;
            else if (start < l) {
                l -= start, r -= start;
                int s1 = (l + x - 1) / x * x;
                if (s1 <= r) {
                    acc += 1;
                    int len = r - s1;
                    acc += len / x;
                }
            } else {
                acc += 1 + (r - start) / x;
            }
        }
        return acc;
    };

    int T = 0, C = 1000000;
    for (int t = 0; t <= 8 * 60; t++) {
        int conf = run(t);
        if (conf < C) T = t, C = conf;
    }
    cout << T << " " << C << "\n";
}

