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

int n;
vector<int> arr;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while (cin >> n && n) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

const int N = 200;

int dp[N][N], pre[N][N], suf[N][N];

void init() {
    arr.assign(n+1, 0); 
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
}

void process() {
    // dp[i][j] = sum(i, j) - min(dp[i+1][j], dp[i+2][j], ... , dp[j][j], 0, dp[i][j-1], dp[i][j-2], ..., dp[i][i])
    
    // init cond: len = 1
    for (int i = 1; i <= n; i++) 
        dp[i][i] = pre[i][i] = suf[i][i] = arr[i]-arr[i-1];
    // dp
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i+len <= n; i++) {
            int j = i+len;
            dp[i][j] = (arr[j]-arr[i-1]) - min({0, suf[i+1][j], pre[i][j-1]});
            pre[i][j] = min(pre[i][j-1], dp[i][j]);
            suf[i][j] = min(suf[i+1][j], dp[i][j]);
        }
    }
    // ans
    cout << dp[1][n] - arr[n] + dp[1][n] << endl;
}

