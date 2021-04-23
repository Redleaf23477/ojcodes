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
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int N, K;
vector<vector<LL>> dp;

void init() {
    cin >> N >> K;
    dp.assign(N+1, vector<LL>(K+1, -1));
}

LL modAdd(LL lhs, LL rhs) {
    constexpr LL MOD = 1e9+7;
    lhs += rhs;
    return (lhs >= MOD? lhs-MOD : lhs);
}

LL f(int n, int k) {
    // cerr << var(n) << var(k) << endl;
    if (dp[n][k] != -1) return dp[n][k];
    if (n == 0) return dp[n][k] = 1;
    if (k == 1) return dp[n][k] = f(n-1, k);
    else return dp[n][k] = modAdd(f(n-1, k), f(N-n, k-1));
}

void process() {
    cout << f(N, K) << endl;
    /*
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    */
}

