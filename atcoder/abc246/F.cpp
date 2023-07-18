#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

LL fastpw(LL x, LL p) {
    if (x == 0) return 0;
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return ans;
}

void solve() {
    int N; cin >> N;
    LL L; cin >> L;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        for (auto ch : str) {
            arr[i] |= (1 << (ch - 'a'));
        }
    }
    LL ans = 0;
    for (int b = 1; b < (1 << N); b++) {
        int common_char = (1 << 26) - 1;
        for (int i = 0; i < N; i++) {
            if ((b >> i) & 1) {
                common_char &= arr[i];
            }
        }

        LL tmp = fastpw(__builtin_popcount(common_char), L);

        int b1cnt = __builtin_popcount(b);
        ans = (ans + tmp * (b1cnt % 2 == 0? -1 : 1) + MOD) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



