#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 998244353;
constexpr LL MAX_N = 10000;
constexpr LL MASK = 1024;

LL pw10[MAX_N];

void init() {
    pw10[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pw10[i] = pw10[i-1] * 10 % MOD;
    }
}

using P = tuple<LL,LL>;  // sum, cnt
P dp[MAX_N+1][MASK];     // non-trailing zero
P dp0[MAX_N+1][MASK];    // trailing zero

void solve_fix_0(const string &num, const int digits_mask) {
    for (size_t i = 1; i <= num.size(); i++) {
        int max_digit = (i == num.size()? num.back() - '0' : 10);
        for (int mask = 0; mask < MASK; mask++) {
            // dp
            for (int d = 1; d < max_digit; d++) if ((mask >> d) & 1) {
                auto &[sum, cnt] = dp[i][mask];
                for (auto subm : {mask, mask ^ (1<<d)}) {
                    auto [sub_sum, sub_cnt] = dp[i-1][subm];
                    sum = (sum + sub_sum + sub_cnt * d % MOD * pw10[i-1]) % MOD;
                    cnt = (cnt + sub_cnt) % MOD;
                }
                if (mask ^ 1) {
                    for (auto subm : {mask, mask ^ 1, mask ^ (1<<d), mask ^ 1 ^ (1<<d)}) {
                        auto [sub_sum, sub_cnt] = dp0[i-1][subm];
                        sum = (sum + sub_sum + sub_cnt * d % MOD * pw10[i-1]) % MOD;
                        cnt = (cnt + sub_cnt) % MOD;
                    }
                }
            }
            // dp0
            for (auto d : {0}) {
                auto &[sum, cnt] = dp0[i][mask];
                for (auto [sub_sum, sub_cnt] : {dp[i-1][mask], dp0[i-1][mask]}) {
                    sum = (sum + sub_sum) % MOD;
                    cnt = (cnt + sub_cnt) % MOD;
                }
            }
        }
    }
}

LL calc_fix_0_ans(int num_len, const int digits_mask) {
    LL ans = 0;
    for (int mask = 0; mask < MASK; maks++) if ((mask & digits_mask) == digits_mask) {
        for (auto [sum, cnt] : {dp[num_len][mask], dp0[num_len][mask]}) {
            ans = (ans + sum) % MOD;
        }
    }
    return ans;
}

void update_dp(const string &num, const int fixed_len, const int used_mask, const int digits_mask) {
    int i = num - fixed_len;
    int max_digit = num[i-1] - '0';
    for (int mask = 0; mask < MASK; mask++) {
        // reset value
        dp[i][mask] = dp0[i][mask] = P(0, 0);
        // dp
        for (int d = 1; d < max_digit; d++) if ((mask >> d) & 1) {
            auto &[sum, cnt] = dp[i][mask];
            for (auto subm : {mask, mask ^ (1<<d)}) {
                auto [sub_sum, sub_cnt] = dp[i-1][subm];
                sum = (sum + sub_sum + sub_cnt * d % MOD * pw10[i-1]) % MOD;
                cnt = (cnt + sub_cnt) % MOD;
            }
            if (mask ^ 1) {
                for (auto subm : {mask, mask ^ 1, mask ^ (1<<d), mask ^ 1 ^ (1<<d)}) {
                    auto [sub_sum, sub_cnt] = dp0[i-1][subm];
                    sum = (sum + sub_sum + sub_cnt * d % MOD * pw10[i-1]) % MOD;
                    cnt = (cnt + sub_cnt) % MOD;
                }
            }
        }
        // dp0
        for (auto d : {0}) {
            auto &[sum, cnt] = dp0[i][mask];
            for (auto [sub_sum, sub_cnt] : {dp[i-1][mask], dp0[i-1][mask]}) {
                sum = (sum + sub_sum) % MOD;
                cnt = (cnt + sub_cnt) % MOD;
            }
        }
    }
}

void solve(const string &num, const int digits_mask) {
    LL ans = 0;
    solve_fix_0(num, digits_mask);
    ans = (ans + calc_fix_0_ans(num.size(), digits_mask)) % MOD;

    int used_mask = 0;
    for (size_t fixed_len = 1; fixed_len <= num.size(); fixed_len++) {
        used_mask |= (1 << (num.end()[-fixed_len] - '0'));
        update_dp(num, fixed_len, used_mask, digits_mask);
        update_ans(num, fixed_len, used_mask, digits_mask);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    // build power 10 mod MOD
    init();
    // input num and reverse
    string num; cin >> num;
    reverse(num.begin(), num.end());
    // input digit as bit string
    int m; cin >> m;
    int digits_mask = 0;
    for (int i = 0; i < m; i++) {
        int d; cin >> d;
        digits_mask |= (1<<d);
    }
    // run
    solve(num, digits_mask);
}

