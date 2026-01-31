#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n; cin >> n;

    // vis[rem * 10 + ending] = come rom what state
    // -1: unvisited, 0: initial states
    vector<int> vis(n * 10, -1);

    queue<tuple<LL, size_t>> q; // (state, length)
    for (int num = 1; num <= 9; num++) {
        // trivial answer
        if (num % n == 0) {
            cout << num << "\n";
            return;
        }

        LL state = num % n * 10 + num;

        if (vis[state] == -1) {
            q.emplace(state, 1);
            vis[state] = 0;
        }
    }
    while (!q.empty()) {
        auto [from_state, len] = q.front(); q.pop();
        LL rem = from_state / 10;
        

        // append num in the lsb
        for (int num = from_state % 10; num <= 9; num++) {
            LL next_rem = (rem * 10 + num) % n;
            LL next_state = next_rem * 10 + num;

            if (vis[next_state] == -1) {
                vis[next_state] = from_state;
                q.emplace(next_state, len + 1);
            }

            if (next_rem == 0) {
                string ans;
                for (int state = next_state; state != 0; state = vis[state]) {
                    ans.push_back('0' + state % 10);
                }
                ranges::reverse(ans);
                cout << ans << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

