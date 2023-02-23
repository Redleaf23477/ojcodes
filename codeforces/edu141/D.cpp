#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    unordered_map<int,LL> now, next;
    now[arr[1]] = 1;
    // push to next
    for (int i = 2; i < n; i++) {
        for (auto [val, cnt] : now) {
            if (val == 0) {
                // both operation yeild same next state
                next[arr[i]] += cnt;
            } else {
                // left -, right +
                next[arr[i] + val] += cnt;

                // left +, right -
                next[arr[i] - val] += cnt;
            }
        }
        for (auto it = next.begin(); it != next.end(); it++) {
            it->second %= MOD;
        }
        // for next iteration
        swap(now, next);
        next.clear();

        /*
        // DEBUG
        for (auto [val, cnt] : now) {
            cerr << "(" << val << ", " << cnt << ")";
        }
        cerr << endl;
        */
    }
    // answer
    LL ans = 0;
    for (auto [val, cnt] : now) {
        ans += cnt;
    }
    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

