#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    size_t n; cin >> n;
    string str; cin >> str;

    if (n == 1) { cout << 1 << "\n"; return; }

    auto state = [](char a, char b, int used) {
        return used * 26 * 26 + (a - 'a') * 26 + (b - 'a');
    };
    auto destate = [](size_t s) {
        int used = s / (26 * 26);
        char a = (s % (26 * 26) / 26) + 'a';
        char b = (s % 26) + 'a';
        return make_tuple(a, b, used);
    };

    int ans = n;

    {
        // state: (a, b, have_i_deleted); I don't apply on str[0] or str[1]
        vector<vector<int>> dp(2, vector<int>(26 * 26 * 2, n));
        for (char a = 'a'; a <= 'z'; a++) for (char b = 'a'; b <= 'z'; b++) {
            dp[1][state(a, b, 0)] = (str[0] != a) + (str[1] != b);
        }
        for (size_t i = 2; i < n; i++) {
            auto &dp_prev = dp[(i - 1) % 2];
            auto &dp_now = dp[i % 2];
            fill(dp_now.begin(), dp_now.end(), n);
            for (size_t s = 0; s < 26 * 26 * 2; s++) {
                auto [a, b, used] = destate(s);
                // state(b, a, used) -> state(a, b, used)
                dp_now[s] = dp_prev[state(b, a, used)] + (str[i] != b);

                if (used == 1) {
                    // deal with used = 0 -> 1
                    // state(a, b, 0) -> state(a, b, 1)
                    dp_now[s] = min(dp_now[s], dp_prev[state(a, b, 0)] + 1);
                }
            }
        }
        for (char a = 'a'; a <= 'z'; a++) for (char b = 'a'; b <= 'z'; b++) {
            ans = min(ans, dp[(n - 1) % 2][state(a, b, n % 2)]);
        }
    }

    if (n >= 3 && n % 2 == 1) {
        // state: (a, b); I apply on str[0]
        // state: (a, b); I apply on str[1]

        for (auto [x, y] : {make_pair(1, 2), make_pair(0, 2)}) {
            vector<vector<int>> dp(2, vector<int>(26 * 26, n));
            for (char a = 'a'; a <= 'z'; a++) for (char b = 'a'; b <= 'z'; b++) {
                dp[0][state(a, b, 0)] = (str[x] != a) + (str[y] != b) + 1;
            }
            for (size_t i = 3; i < n; i++) {
                auto &dp_prev = dp[(i - 1) % 2];
                auto &dp_now = dp[i % 2];
                fill(dp_now.begin(), dp_now.end(), n);
                for (size_t s = 0; s < 26 * 26; s++) {
                    auto [a, b, used] = destate(s);
                    // state(b, a, used) -> state(a, b, used)
                    dp_now[s] = dp_prev[state(b, a, used)] + (str[i] != b);
                }
            }
            for (char a = 'a'; a <= 'z'; a++) for (char b = 'a'; b <= 'z'; b++) {
                ans = min(ans, dp[(n - 1) % 2][state(a, b, 0)]);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

