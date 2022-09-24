#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    vector<int> arr(10);
    for (auto &x : arr) cin >> x;
    list<int> ans;

    if (arr[0] == 1 && *max_element(arr.begin() + 1, arr.end()) == 0) {
        cout << 0 << "\n"; return;
    }

    auto get_small = [&](int exclude) {
        for (int i = 0; i < 10; i++) {
            if (i != exclude && arr[i] > 0) return i;
        }
        return -1;
    };

    auto dirty_fix = [&](const list<int>::iterator BEG, int fix) {
        for (auto it = BEG; it != ans.end(); it++) {
            if (*it == fix) continue;
            arr[*it] += 1;
            *it = -1;
        }
        for (auto it = BEG; it != ans.end(); it++) {
            if (*it == fix) continue;
            if (it == ans.begin()) {
                int x = get_small(0);
                *it = x, arr[x]--;
            } else {
                int x = get_small(-1);
                *it = x, arr[x]--;
            }
        }
    };

    // greedy
    // 1) not zero
    int x = get_small(0);
    if (x == -1) {
        cout << -1 << "\n"; return;
    } else {
        ans.emplace_back(x), arr[x]--;
    }
    // 2) while ok push different
    while (true) {
        x = get_small(ans.back());
        if (x == -1) break;
        ans.emplace_back(x), arr[x]--;
    }
    // 3) linear search a good pos for remaining
    for (int d = 0; d < 10; d++) {
        // there will be only one number left at most
        if (arr[d] == 0) continue;
        // get first d
        auto it = find(ans.begin(), ans.end(), d);
        for (; arr[d] > 0; arr[d]--) {
            if (it != ans.end() && *it == d) {
                if (it == ans.begin()) {
                    cout << -1 << "\n"; return;
                }
                it--;
            }
            it = ans.insert(it, d);
        }
        // whatever, dirty fix
        dirty_fix(it, d);
    }

    if (ans.front() == 0) {
        cout << -1 << "\n"; return;
    }

    for (auto x : ans) cout << x;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

