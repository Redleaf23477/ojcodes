#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

vector<LL> prod_sum(25, 1);
vector<LL> prod_sum_inv(25, 1);

LL C[25][25];

LL get_max_size(LL l, LL r) {
    LL ans = 0;
    while (l <= r) ans++, l *= 2;
    return ans;
}

pair<LL,LL> get_max_three(LL l, LL r, LL max_size) {
    LL tmp = l;
    for (LL i = 1; i < max_size; i++) {
        tmp *= 2;
    }
    LL ans = 0;
    for (int i = 1; i < max_size && tmp / 2 * 3 <= r; i++) {
        ans++;
        tmp = tmp / 2 * 3;
    }
    return make_pair(ans, tmp / l);
}

LL fastpw(LL a, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        p /= 2;
    }
    return ans;
}

void solve() {
    LL l, r; cin >> l >> r;
    LL max_size = get_max_size(l, r);
    auto [max_three, prod3] = get_max_three(l, r, max_size);

    // cerr << "xx" << max_size << " " << max_three << " " << prod3 << endl;

    LL final_ans = 0;
    for (LL three = max_three; three >= 0; three--, prod3 = prod3 / 3 * 2) {
        LL low = l, high = r, mid, ans = low;
        while (low <= high) {
            mid = (low + high) / 2;
            if (mid * prod3 <= r) {
                ans = mid, low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // cerr << "three = " << three << ", ans = " << ans << endl;
        // final_ans = (final_ans + prod_sum[max_size - 1] * prod_sum_inv[three] % MOD * prod_sum_inv[max_size - 1 - three] % MOD * (ans - l + 1) % MOD) % MOD;
        final_ans = (final_ans + C[max_size-1][three] * (ans - l + 1) % MOD) % MOD;
    }
    cout << max_size << " " << final_ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    /*
    for (LL i = 1; i <= 24; i++) {
        prod_sum[i] = prod_sum[i-1] * i % MOD;
        prod_sum_inv[i] = fastpw(prod_sum[i], MOD - 2);
    }
    */
    for (LL i = 0; i < 25; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    while (T--) {
        solve();
    }
}

