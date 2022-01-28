#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 998244353;
constexpr LL MAX_N = 10000;

LL pw10[MAX_N];

void init() {
    pw10[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pw10[i] = pw10[i-1] * 10 % MOD;
    }
}

LL for_fun(size_t len, const string &num, const int digits, const int used) {
    using P = tuple<LL,LL>;  // (sum, cnt) under mod
    vector<vector<P>> dp(num.size() - len, vector<P>(1024, P(0, 0)));
    // dp[0][S] := right most digit
    for (int d = 0; d < 10; d++) {
        dp[0][used | (1<<d)] = P(d, 1);
    }
    // dp[i][S] := i-th digit from right
    for (int i = 0; i+1 < num.size() - len; i++) {
        for (int s = 0; s < 1024; s++) {
            const int BOUND = (i == num.size() - len - 1? num[len] - '0' : 10);
            for (int b = 0; b < BOUND; b++) if ((s >> b) & 1) {
                // place b in i-th digit
                auto &[sum, cnt] = dp[i][s];
                {
                    // case: from dp[i+1][s ^ (1<<b)]
                    auto &[sum_sub, cnt_sub] = dp[i+1][s ^ (1<<b)];
                    sum = (sum + sum_sub + b * pw10[i] % MOD + cnt_sub % MOD) % MOD;
                    cnt = (cnt + cnt_sub) % MOD;
                }
                {
                    // case: from dp[i+1][s]
                    auto &[sum_sub, cnt_sub] = dp[i+1][s];
                    sum = (sum + sum_sub + b * pw10[i] % MOD + cnt_sub % MOD) % MOD;
                    cnt = (cnt + cnt_sub) % MOD;
                }
            }
        }
    }
    // return answer
    LL head = 0, ans = 0;
    for (size_t i = 0; i < len; i++) {
        head = (head + (num[i] - '0') * pw10[num.size() - i - 1] % MOD) % MOD;
    }
    for (int s = 0; s < 1024; s++) if ((s & digits) == digits) {
        auto [sum, cnt] = dp[num.size() - len - 1][s];
        ans = (ans + head * cnt % MOD + sum) % MOD;
    }
    cerr << "ans = " << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    init();
    string n; cin >> n;
    int m; cin >> m;
    int digits = 0;
    for (int i = 0; i < m; i++) {
        int d; cin >> d;
        digits |= (1<<d);
    }

    LL ans = 0;
    int used = 0;
    for (size_t i = 0; i <= n.size(); i++) {
        if (i > 0) {
            char tp = n[i-1];
            used |= (1<<(tp-'0'));
        }
        ans = (ans + for_fun(i, n, digits, used)) % MOD;
    }
    /*
    // add n
    for (size_t i = 0; i < n.size(); i++) {
        ans = (ans + pw10[i] * (n[n.size() - 1 - i]-'0')) % MOD;
    }
    */
    cout << ans << "\n";
}

