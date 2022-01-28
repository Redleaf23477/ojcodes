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
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init() {
}

constexpr int INF = 200000, C = 0, J = 1;

void process() {
    int cj, jc; cin >> cj >> jc;
    string str; cin >> str;
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(2, INF));
    if (str[0] == '?') dp[0][C] = dp[0][J] = 0;
    else if (str[0] == 'C') dp[0][C] = 0;
    else dp[0][J] = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] == '?') {
            dp[i][C] = min(dp[i-1][C], dp[i-1][J]+jc);
            dp[i][J] = min(dp[i-1][C]+cj, dp[i-1][J]);
        } else if (str[i] == 'C') {
            dp[i][C] = min(dp[i-1][C], dp[i-1][J]+jc);
        } else {
            dp[i][J] = min(dp[i-1][C]+cj, dp[i-1][J]);
        }
    }
    cout << min(dp[n-1][C], dp[n-1][J]) << endl;
}

