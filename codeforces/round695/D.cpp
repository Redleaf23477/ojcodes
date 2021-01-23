// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

const LL MOD = (LL)1e9+7;
const LL N = 5003;
LL n, k, q;
LL dp[N][N];
vector<LL> w;

void init() {
    cin >> n >> k >> q;
    w.resize(n); for (auto &x : w) cin >> x;
}


void process() {
    for (int i = 0; i < n; i++) dp[0][i] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
            if (j-1 >= 0) dp[i][j] += dp[i-1][j-1];
            if (j+1 < n) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }
    /*
    cerr << "dp = ";
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    */
    LL ans = 0;
    vector<LL> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            cnt[i] = (cnt[i] + dp[j][i]*dp[k-j][i]) % MOD;
        }
    }
    for (int i = 0; i < n; i++) ans = (ans + w[i]*cnt[i]) % MOD;
    while (q--) {
        LL idx, val; cin >> idx >> val; idx--;
        LL sub = w[idx] * cnt[idx] % MOD;
        w[idx] = val;
        ans = (ans - sub + w[idx]*cnt[idx]%MOD + MOD) % MOD;
        cout << ans << endl;
    }
}

