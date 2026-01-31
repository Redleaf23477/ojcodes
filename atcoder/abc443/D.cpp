#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> r(n);
    for (auto &x : r) {
        cin >> x;
        x = n - x;
    }

    priority_queue<tuple<int, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(r[i], i);
    }

    vector<int> final_pos(n, -1);
    set<int> finalized;
    while (!pq.empty()) {
        auto [row, i] = pq.top(); pq.pop();

        final_pos[i] = row;

        if (finalized.size() == 0) {
            // do nothing
        } else if (finalized.size() == 1) {
            int j = *finalized.begin();
            final_pos[i] = max(final_pos[i], final_pos[j] - abs(j - i));
        } else {
            auto it = finalized.lower_bound(i);
            // deal with right
            if (it != finalized.end()) {
                int j = *it;
                final_pos[i] = max(final_pos[i], final_pos[j] - abs(j - i));
            }
            // deal with left
            if (it != finalized.begin()) {
                it--;
                int j = *it;
                final_pos[i] = max(final_pos[i], final_pos[j] - abs(j - i));
            }
        }

        finalized.insert(i);
    }

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(r[i] - final_pos[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

