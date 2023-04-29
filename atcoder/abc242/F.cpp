#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;
constexpr LL MAX = 3000;

LL fastpw(LL a, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        p /= 2;
    }
    return ans;
}

vector<LL> fac, fac_inv;
void build_fac() {
    fac.assign(MAX, 1);
    fac_inv.assign(MAX, 1);
    for (LL i = 1; i < MAX; i++) fac[i] = i * fac[i-1] % MOD;
    fac_inv[MAX-1] = fastpw(fac[MAX-1], MOD-2);
    for (LL i = MAX-2; i >= 0; i--) {
        fac_inv[i] = fac_inv[i+1] * (i+1) % MOD;
    }
    for (int i = 0; i < MAX; i++) {
        assert(fac[i] * fac_inv[i] % MOD == 1); 
    }
}

LL choose(LL tot, LL c1) {
    return fac[tot] * fac_inv[c1] % MOD * fac_inv[tot - c1] % MOD;
}

LL choose(LL tot, LL c1, LL c2) {
    return fac[tot] * fac_inv[c1] % MOD * fac_inv[c2] % MOD * fac_inv[tot - c1 - c2] % MOD;
}

void solve() {
    LL R, C, B, W; cin >> R >> C >> B >> W;
    auto put_in_box_cover_all = [&](LL k) {
        vector<vector<LL>> dp(R+1, vector<LL>(C+1, 0));
        for (LL r = 1; r <= R; r++) for (LL c = 1; c <= C; c++) {
            if (r * c < k) {
                // too small
                dp[r][c] = 0;
            } else if (r * c - k < min(r, c)) {
                // just put, base case
                dp[r][c] = choose(r * c, k);
            } else {
                // enumerate missing cols and rows
                LL bad = 0;
                for (LL mr = 0; mr <= r; mr++) for (LL mc = 0; mc <= c; mc++) {
                    if (mr == 0 && mc == 0) continue;
                    bad = (bad + choose(r, mr) * choose(c, mc) % MOD * dp[r-mr][c-mc] % MOD) % MOD;
                }
                dp[r][c] = (choose(r * c, k) - bad + MOD) % MOD;
            }
        }
        return dp;
    };
    auto put_B = put_in_box_cover_all(B);
    auto put_W = put_in_box_cover_all(W);

    /*
    cerr << "debug: " << R << ", " << C << ", " << B << endl;
    for (int r = 0; r <= R; r++) {
        for (int c = 0; c <= C; c++) {
            cerr << put_B[r][c] << " ";
        }
        cerr << endl;
    }
    */

    auto calc = [&](LL br, LL bc, LL wr, LL wc) {
        LL ans = 1;
        // put B rooks in br * bc
        ans = ans * put_B[br][bc] % MOD;
        // put W rooks in wr * wc
        ans = ans * put_W[wr][wc] % MOD;
        // permute the br + wr rows
        ans = ans * choose(R, br, wr) % MOD;
        // permute the bc + wc cols
        ans = ans * choose(C, bc, wc) % MOD;

        return ans;
    };
    LL ans = 0;
    for (LL br = 0; br <= R; br++) for (LL bc = 0; bc <= C; bc++) {
        if (br * bc < B) continue;
        for (LL wr = 0; br + wr <= R; wr++) for (LL wc = 0; bc + wc <= C; wc++) {
            if (wr * wc < W) continue;
            ans = (ans + calc(br, bc, wr, wc)) % MOD;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    build_fac();
    solve();
}



