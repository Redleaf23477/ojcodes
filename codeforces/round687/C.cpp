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
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, p, k, x, y;
int ones;
vector<char> arr;

void init() {
    cin >> n >> p >> k; 
    arr.resize(n+1, '0');
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ones += (arr[i] == '1');
    }
    cin >> x >> y;
}

void process() {
    vector<int> dp(n+1, 0);
    for (int i = n; i > 0; i--) {
        if (arr[i] == '0') dp[i]++;
        if (i+k <= n) dp[i] += dp[i+k];
    }
    int ans = x*dp[p];
    for (int i = 1; i+p <= n; i++) {
        int tmp = dp[i+p];
        ans = min(i*y + tmp*x, ans);
    }
    cout << ans << endl;
}

