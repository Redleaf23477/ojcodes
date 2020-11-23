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

const LL MOD = 998244353;

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

LL fastpw(LL x, LL p) {
    if (p == 0) return 1;
    else if (p%2 == 0) return fastpw(x*x%MOD, p/2);
    else return x*fastpw(x*x%MOD, p/2)%MOD;
}

LL modInv(LL x) { return fastpw(x, MOD-2); }

LL n; 

void init() {
    cin >> n;
}

void process() {
    vector<LL> dp(n+1, 0), pre(n+1, 0);
    dp[0] = 1, dp[1] = 1, dp[2] = 1;
    pre[0] = 1, pre[1] = 1, pre[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = pre[i-1];
        pre[i] = (pre[i-2]+dp[i])%MOD;
    }
    cout << dp[n] * fastpw(modInv(2), n) % MOD << endl;
    /*
    cerr << "dp = ";
    for (auto x : dp) cerr << x << " ";
    cerr << endl;
    */
}

