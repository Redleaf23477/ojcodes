#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    /*  t_i + x_i <= s_j + x_j
     *  --> x_j >= x_i + (t_i - s_j)
     *  Objective: minimize Sum(x_1 + x_2 + ... + x_m)
     *
     *  For any x_j, it must follow all i that goes to j:
     *  --> x_j >= max(x_i + (t_i - s_j) | i goes to j)
     *  --> longest path to j is a solution, and "=" holds
     */

    size_t n, m; cin >> n >> m;
    vector<LL> x(m); cin >> x[0];

    // event: {time, type (arrive, depart), station (arrive, depart), idx}
    enum Event { arrive, depart };
    vector<tuple<LL, Event, size_t, size_t>> train;
    for (size_t i = 0; i < m; i++) {
        int a, b, s, t; cin >> a >> b >> s >> t; a--, b--;
        train.emplace_back(s, Event::depart, a, i);
        train.emplace_back(t, Event::arrive, b, i);
    }
    sort(train.begin(), train.end());

    vector<LL> tmp(n, 0);
    for (auto [tim, event, city, i] : train) {
        if (event == Event::arrive) {
            // tmp[b[i]] = max(tmp[b[i]], x[i] + t[i]);
            tmp[city] = max(tmp[city], x[i] + tim);
        } else if (i != 0) {
            // x[i] = max(0, tmp[a[i]] - s[i]);
            x[i] = max(0ll, tmp[city] - tim);
        }
    }

    for (auto it = next(x.begin()); it != x.end(); it++) cout << *it << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

