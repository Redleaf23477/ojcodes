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

int n;
vector<int> a, b;
const int N = 101;
const int INF = 2*N*N*N;
int dp[N][N][N*N];

void init() {
    cin >> n;
    a.resize(n+1), b.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k <= 100*n; k++)
        dp[i][j][k] = -INF;
}

void process() {
    int S = 0; for (int i = 1; i <= n; i++) S += b[i];
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        // init
        /*
        for (int pick = 1; pick <= i; pick++) for (int cap = 1; cap <= 100*pick; cap++) {
            dp[i][pick][cap] = 0;
        }
        */
        dp[i][0][0] = 0;
        // dp
        for (int pick = 1; pick <= i; pick++) for (int cap = 1; cap <= 100*pick; cap++) {
            dp[i][pick][cap] = dp[i-1][pick][cap];
            if (cap >= a[i]) {
                dp[i][pick][cap] = max( 
                    dp[i][pick][cap], 
                    min(dp[i-1][pick-1][cap-a[i]] + b[i], cap*2) // pick i-th 
                );
            }
        }
    }
    for (int pick = 1; pick <= n; pick++) {
        int ans = 0;
        for (int cap = 1; cap <= 100*pick; cap++) {
            ans = max(ans, min(2*cap, dp[n][pick][cap]+S));
        }
        if (ans % 2 == 0) cout << ans/2 << " ";
        else cout << ans/2 << ".5" << " ";
    }
    cout << endl;
}

